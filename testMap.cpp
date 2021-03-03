/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/13
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include <map>

#include "Util.hpp"
class Test : public MAP_VALUE{
    int num = 10;
public:

    string print() const override {
        return MAP_VALUE::print();
    }
};

int main(){
//    std::map<int, MAP_VALUE> testMap{};
//    std::map<int, MAP_VALUE> testMap{};
//    testMap.insert({20,'a'});
//    std::cout << "key == "<< testMap.begin()->first <<", value address" << &(testMap.begin()->second)  << std::endl;
//    testMap.insert({10,'b'});
//    std::cout << "key == " <<std::next(testMap.begin(),1)->first << ", value address" << &(std::next(testMap.begin(),1)->second)  << std::endl;
//    testMap.insert({999,'c'});
//
//
//    map_util::print(testMap);
//
//    std::set<int> testSet{1111};
//    std::cout << *testSet.begin() << std::endl;

    std::unordered_map<int,int> test{};
    std::cout << test[22] << std::endl;

}