/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"
struct Cache{
    int value;
    int time = 0;
};
class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        int ret;
        if (mapping.count(key) <=0){
            ret =  -1;
        }else{
            //�޸ĸ�key�ķ���ʱ��
            mapping[key].time = getIndex();
            ret =  mapping[key].value;
        }
//        std::cout << ret << std::endl;
        return ret;
    }

    void put(int key, int value) {
        if (capacity == 0){
            return;
        }
        if (mapping.count(key) > 0){
            mapping[key] = {value,getIndex()};
            return;
        }
        if (mapping.size() == capacity){
            //�滻�㷨
            int replace_key = mapping.begin()->first;
            int time =  mapping.begin()->second.time;
            for(auto pair:mapping){
                if (pair.second.time < time){
                    replace_key = pair.first;
                    time = pair.second.time;
                }
            }
//            std::cout << "put"<<key<<"erase" << replace_key << std::endl;
            mapping.erase(replace_key);
            mapping[key] = {value,getIndex()};
//            print(mapping);
        }else{
            mapping[key] = {value,getIndex()};
        }


    }

private:
    int capacity;
    int index;
    std::map<int,Cache> mapping{};
    int getIndex(){
        return ++index;
    }

    static void print(const std::map<int,Cache>& input){
        std::cout << "[";
        for (auto &item:input){
            std::cout << "key:" << item.first << "value:" << item.second.value <<"," << std::endl;
        }
        std::cout << "]" << std::endl;

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