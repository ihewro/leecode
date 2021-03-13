/**
 * Copyright (c) 2020, SeekLoud Team.
 * Manager:
    * 2020/12/24: hewro
 * Developer: hewro
 * Description: 
 * Refer:
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using std::vector;


class Solution {
public:

    //确定一定是只发一个糖果的人，就能根据这个人推算出所有人该发多少个糖果
    std::pair<vector<int>,bool> getMinPoint(vector<int>& ratings){

        ratings.insert(ratings.begin(),INT_MAX);
        ratings.push_back(INT_MAX);

        //rating 头和尾插入两个辅助数字
        bool startIsMinPoint = ratings[1] < ratings[2];
        vector<int> extremum_point_list;

        std::cout << "ratings.size()" << ratings.size() << std::endl;
        for (int i = 1; i < ratings.size()-1; ++i) {
            if (ratings[i] == ratings[i-1]){
                if (ratings[i] < ratings[i+1]){
                    ratings[i] = ratings[i] - 1;
                }else if (ratings[i] > ratings[i+1]){
                    ratings[i] = ratings[i] + 1;
                }
            }


            if (ratings[i] == ratings[i+1]){
                if (ratings[i] < ratings[i-1]){
                    ratings[i] = ratings[i] - 1;
                }else if (ratings[i] > ratings[i-1]){
                    ratings[i] = ratings[i] + 1;
                }
            }

            if (ratings[i] < ratings[i+1] && ratings[i] < ratings[i-1]){//当前点为最低点
                std::cout << "min" << i << std::endl;
                extremum_point_list.push_back(i);
            }

            if (ratings[i] > ratings[i-1] && ratings[i] > ratings[i+1]){
                std::cout << "max" << i<< std::endl;
                extremum_point_list.push_back(i);
            }
        }

        return {extremum_point_list,startIsMinPoint};
    }

    int distributeCandy(vector<int>& ratings,int low_position){
        vector<int> candyNum(ratings.size());//分配的糖果数目
        //对所有的最低点左右两边进行赋值,直到遇到另一个最低点
        int curr = ratings[low_position];
        int ret = curr;
        if (low_position == 0 || low_position == ratings.size()-1){
            std::cout << "no" << low_position << std::endl;
        }

        if (low_position != ratings.size() - 2){
            std:: cout << "right" << std::endl;
            for (int i =low_position;i < ratings.size()-2; i++){//计算该点右侧的值
//                std::cout << "ratings[i]" << ratings[i] << "ratings[i+1]" << ratings[i+1] << std::endl;
                if (ratings[i+1] > ratings[i]){

                    curr = curr + 1;//i+1的值
                    std::cout << "curr+" << curr << std::endl;

                    ret += curr;
                }else{
                    curr = curr - 1;
                    std::cout << "curr-" << curr << std::endl;

                    ret += curr;
                }
            }
        }


        if (low_position != 1){
            std:: cout << "left" << std::endl;

            for (int i = low_position-1; i > 0 ; i--) {//计算该点左侧的值
                if (ratings[i-1] > ratings[i]){
                    curr = curr + 1;
                    ret += curr;
                }else{
                    curr = curr - 1;
                    ret += curr;
                }
            }
        }
        return ret;
    }


    int candy(vector<int>& ratings) {
        vector<int> extremum_point_list;
        bool startIsMinPoint = false;
        std::tie(extremum_point_list,startIsMinPoint) = getMinPoint(ratings);

        int i = startIsMinPoint ? 0 : 1;
        int low_position = 1;
        int max_length = 0;
        while (i < extremum_point_list.size()) {
            int length = std::max(extremum_point_list[i-1] - extremum_point_list[i], extremum_point_list[i+1] - extremum_point_list[i]);
            if (length > max_length){
                max_length = length;
                low_position = extremum_point_list[i];
            }
            i+=2;
        }
        std::cout << "low_position" << low_position << std::endl;
        return distributeCandy(ratings,low_position);
    }
};

int main(){
    Solution solution;
    vector<int> input = {1,0,2};
    std::cout << solution.candy(input) << std::endl;
}