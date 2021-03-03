/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/13
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */


#include "Util.hpp"

int main(){
//    std::list<int> test_{1,3};
//    test_.insert((test_.begin()),20);
//
//    for (auto  item: test_){
//        std::cout << item << ",";
//    }

    vector<int> test_{1,2,3,4,5,5,7};
    for(auto it = test_.begin();it != test_.end();it++){
        std::cout << *it << std::endl;
//        auto temp = it;
        test_.erase(it);
        std::cout << *it << std::endl;
    }

}
