/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"

struct DListNode{
    int key;
    int value;
    DListNode * prev = nullptr;
    DListNode * next = nullptr;
};

class MyList{
private:

    //虚拟头尾节点，为了插入的节点时候，不需要判断尾节点是否存在
    DListNode * head;
    DListNode * tail;

private:
    void removeNode(DListNode * node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        this->size--;

    }

    void insertNode2Front(DListNode * node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        this->size++;
    }

public:

    int size = 0;
    int capacity = 0;

    MyList() {
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }


    int pop_back(){
        auto node = tail->prev;
        int key = node->key;
        removeNode(node);
        delete node;
        return key;
    }

    void move_front(DListNode * node){
        removeNode(node);
        insertNode2Front(node);
    }
    DListNode * push_front(int key,int value){
        auto node  = new DListNode({key,value});
        insertNode2Front(node);
        return node;
    }

};
class LRUCache {
private:

    MyList _list;
    std::unordered_map<int,DListNode *> map;

public:
    LRUCache(int capacity) {
        _list.capacity = capacity;
    }

    int get(int key) {
        if (map.count(key)<=0){
            return -1;
        }else{
            //更新标记
            _list.move_front(map[key]);
            return map[key]->value;
        }
    }

    void put(int key, int value) {
        //判断元素是否在 list中
        if (map.count(key)){
            //修改值
            map[key]->value = value;
            //节点移动链表头部
            _list.move_front(map[key]);
        }else{
            if (_list.size >= _list.capacity){
                //删除最久的元素
                map.erase( _list.pop_back());
                //插入该元素
                map.insert({key,_list.push_front(key, value)});
            }else{
                //插入元素
                map.insert({key,_list.push_front(key, value)});
            }
        }
    }
};

int main(){
    LRUCache lruCache(2);
    lruCache.put(1,1);
    lruCache.put(2,2);

    lruCache.get(1);


    lruCache.put(3,3);


    lruCache.get(2);

    lruCache.put(4,4);


    lruCache.get(1);
    lruCache.get(3);
    lruCache.get(4);

}