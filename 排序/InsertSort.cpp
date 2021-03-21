//
// Created by hewro on 2021/3/19.
//
#include "Util.hpp"
//void insertSort(vector<int> &input){
//    for (int i = 1; i < input.size(); ++i) {
//        //每一趟把一个元素插入到有序区的合适位置
//        int value = input[i];
//        for (int j = i-1; j >=0  ; j--) {
//            if (value >= input[j]){
//                break;
//            }else{
//                input[j + 1] = input[j];//待排元素是 j+1的位置，与 j 位置进行交换位置
//                input[j] = value;
//            }
//        }
//    }
//}

void insertSort(vector<int> &input){
    for (int i = 1; i < input.size(); ++i) {
        //每一趟把一个元素插入到有序区的合适位置
        int value = input[i];
        //使用二分查找查找右边界，这样移动的次数少
        int left = 0,right = i - 1;
        while (left <= right){
            int mid  = (right + left) / 2;
            if (input[i] > input[mid]){
                left = mid + 1;//右侧区间
            }else if ( input[mid] > input[i]){
                right = mid - 1;//左侧区间
            } else if (input[i] == input[mid]){
                left = mid + 1;//找右侧区间
            }
        }
        int target = right+1;//插入的位置
        std::cout << target << std::endl;
        int end = i-1;
        //移动
        while (end >= target){
            input[end+1] = input[end] ;
            end--;
        }
        input[target] = value;
    }
}

int main(){
    vector<int> t{6,4,3,2,2,2,2,2,7};
    insertSort(t);
    vector_util::print(t);
}
