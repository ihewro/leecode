/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/23
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"
class Solution {
public:
    int hammingDistance(int x, int y) {
        auto x_2 = trans2Base(x);
        auto y_2 = trans2Base(y);

        int max_len = std::max(x_2.size(),y_2.size());

        int ret =  0;
        for (int i = 0; i < max_len; ++i) {
            int x_index = x_2.size() - i -1;
            int y_index = y_2.size() - i -1;

            if (x_index >=0 && y_index >= 0){
                if (x_2[x_index] != y_2[y_index]){
                    ret++;
                }
            }else{
                if (x_index >=0){
                    if (x_2[x_index]){
                        ret++;
                    }
                }else if (y_index >=0){
                    if (y_2[y_index]){
                        ret++;
                    }
                }


            }

        }


        return ret;
    }

    vector<int> trans2Base(int num){
        vector<int> ret{};
        while (num > 0){
            ret.push_back(num % 2);
            num = num/2;
        }
        std::reverse(ret.begin(),ret.end());
//        vector_util::print(ret);
        return ret;
    }
};

int main(){
    int x = 1;
    int y = 4;
    Solution solution;
    std::cout << solution.hammingDistance(x,y) << std::endl;
}