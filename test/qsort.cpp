//
// Created by hewro on 2021/3/16.
//
#include "Util.hpp"

/**
 * 返回基准的位置
 */
int partition(int start,int end,vector<int> &input){
    if (start >= end){
        return std::min(start,end);
    }
    int pivot = input[start];
    int i=start,j=end;
    while(i!=j){
        while(i<j && input[j] > pivot){
            j--;
        }
        input[i] = input[j];

        while(i<j && input[i]<= pivot){
            i++;
        }
        input[j] = input[i];
    }

    input[i] = pivot;
    return i;

}


void qsort(int i,int j,vector<int> &input){
    if (i >= j){
        return;
    }
    int mark = partition(i,j,input);

    qsort(i,mark-1,input);
    qsort(mark+1,j,input);
}


int main(){

    vector<int> input{4,3,6,2,1};
    qsort(0,input.size()-1,input);
    vector_util::print(input);
}