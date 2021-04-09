/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"

class LRUCache {
public:
    std::list<std::pair<int,int>> list;//头部是最就被使用的，尾部是最久未被使用的，存储所有的 <key,value>
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> map;//key-><key,value>
    int capacity = 0;
    int size = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if(map.count(key)){
            //更新当前 key 到头部
            //移除
            auto it = map[key];
            std::pair<int,int> tmp = {(*it).first,(*it).second};
            list.erase(it);

            //加入
            list.push_front(tmp);
            map[key] = list.begin();
            return (*map[key]).second;
        }else{
            return -1;
        }
    }

    void put(int key, int value) {
        if (get(key) != -1){
            map[key]->second = value;
        }else{//插入
            if  (size >= capacity){//如果容量上限了
                //找到最后一个元素
                auto last = list.end();
                last--;

                //移除
                map.erase((*last).first);
                list.erase(last);//需要换出

                //加入
                list.push_front({key,value});
                map[key] = list.begin();

            }else{//如果容量没有上限，需要更新数据的最近被使用
                //加入
                list.push_front({key,value});
                map[key] = list.begin();
                size++;
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

//    lruCache.put(1,1);
//    lruCache.put(2,2);
//
//    std::cout << lruCache.get(1) << std::endl;
//
//
//    lruCache.put(3,3);
//
//
//    std::cout << lruCache.get(2) << std::endl;
//
//    lruCache.put(4,4);
//
//
//    std::cout << lruCache.get(1) << std::endl;
//    std::cout << lruCache.get(3) << std::endl;
//    std::cout << lruCache.get(4) << std::endl;

}