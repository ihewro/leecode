/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"


template<typename T>
class Mlist{
public:
     struct ListNode{
        T item;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
    };
private:
    ListNode* head;

public:
    Mlist(){
        head=new ListNode{};
        head->next = head;
        head->prev = head;
    }
    void push_front(T item){
        ListNode* node= new ListNode({item});
        auto tmp = head->next;
        head->next = node;
        node->next = tmp;
        node->prev = head;
        tmp->prev = node;
    }

    void erase(ListNode* node){
        auto node_next = node->next;
        auto node_prev = node->prev;
        node_prev->next = node_next;
        node_next->prev = node_prev;
        delete node;
    }

    ListNode* begin(){
        return head->next;
    }

    ListNode* last(){
        return head->prev;
    }
};

class LRUCache {
public:
    Mlist<std::pair<int,int>> list;//头部是最就被使用的，尾部是最久未被使用的，存储所有的 <key,value>
    std::unordered_map<int,Mlist<std::pair<int,int>>::ListNode*> map;//key-><key,value>
    int capacity = 0;
    int size = 0;//节点数目
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void pop_back(Mlist<std::pair<int,int>>::ListNode* it,bool isDeleteKey=false){
        int key = it->item.first;
        list.erase(it);
        if(isDeleteKey){
            map.erase(key);
        }
        size--;
    }
    void push_front(int key,int value){
        list.push_front({key,value});
        map[key] = list.begin();
        size++;
    }

    int get(int key) {
        if(map.count(key)){
            //找到当前节点
            auto it = map[key];
            int key = (*it).item.first; int value = (*it).item.second;
            //移除
            pop_back(it);
            //加入
            push_front(key,value);
            return (*map[key]).item.second;
        }else{
            return -1;
        }
    }
    void put(int key, int value) {
        if (get(key) != -1){
            map[key]->item.second = value;
        }else{//插入
            if  (size >= capacity){//如果容量上限了
                //找到最后一个元素
                auto last = list.last();
                //移除
                pop_back(last,true);
                //加入
                push_front(key,value);
            }else{//如果容量没有上限，需要更新数据的最近被使用
                //加入
                push_front(key,value);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache lruCache(2);

    lruCache.put(1,1);
    lruCache.put(2,2);

    std::cout << lruCache.get(1) << std::endl;


    lruCache.put(3,3);


    std::cout << lruCache.get(2) << std::endl;

    lruCache.put(4,4);


    std::cout << lruCache.get(1) << std::endl;
    std::cout << lruCache.get(3) << std::endl;
    std::cout << lruCache.get(4) << std::endl;

}