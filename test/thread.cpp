#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#define FIBER_STACK 1024*64

ucontext_t *context;
int currentid;

static void
signal_handler(int signum) //设置信号量触发协程切换
{
    printf("uthread %d switching to uthread %d...\n",currentid,(currentid+1)%2);
    int temp=currentid;
    currentid=(currentid+1)%2;
    int error=swapcontext(&context[temp],&context[currentid]);
    if(error==-1)
    {
        printf("swap failed\n");
    }
}



void *work1(void *arg) //pthread创建的worker线程工作内容，也是uthread0的工作内容
{
    signal(SIGUSR1, signal_handler);
    int a=0;
    while(1)
    {
        sleep(1);
        a+=1;
        printf("uthread 0: a=%d\n",a);
    }
    return NULL;
}
void work2() //uthread1工作内容
{
    signal(SIGUSR1, signal_handler);
    int a=999999;
    while(1)
    {
        sleep(1);
        a-=1;
        printf("uthread 1: a=%d\n",a);
    }
}

void initialize()
{
    context=(ucontext_t *)malloc(sizeof(ucontext_t)*2);
    currentid=0;
    getcontext(&context[1]);
    context[1].uc_link = 0;
    context[1].uc_stack.ss_sp = malloc( FIBER_STACK );
    context[1].uc_stack.ss_size = FIBER_STACK;
    context[1].uc_stack.ss_flags = 0;
    makecontext(&context[1],&work2,0); //使用makecontext创建协程上下文之前，要初始化上述一些栈的变量以及分配空间，不然段错误
}


int main(int argc, char** argv)
{
    initialize();

    pthread_t t;
    int error = pthread_create(&t, NULL, work1, NULL);
    if(error!=0)
    {
        printf("can't create thread\n");
    }
    pthread_join(t,NULL);

    return 0;
}