/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/22
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "../Utils/Util.hpp"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {

        int index = A.size()-1;
        while (index >=0 || K > 0) {
            int temp = K % 10;
            K /= 10;
            std::cout << "end" << temp << std::endl;
            if (index >= 0){
                if (plus(A, index,temp)){
                    index = 1;
                }
            }else{
                A.insert(A.begin(),temp);
//                index=1;
            }
            index --;
        }

        return A;
    }

    bool plus(vector<int>&ret,int index, int k){
        int value = ret[index] + k;
//        std::cout << "ret["<<index<<"]:"<<ret[index]<< "  k:" << k << "  value:" << value <<std::endl;
        bool isHaveNeed = false;
        if (value >= 10){
            value = value % 10;
            isHaveNeed = true;
        }
//        std::cout << "ret["<<index<<"]:"<<ret[index]<< "  k:" << k << "  value:" << value <<std::endl;

        ret[index] = value;
        if (isHaveNeed){
            if (index ==0){
                ret.insert(ret.begin(),1);
                return true;
            }else{
                return plus(ret,index-1,1);
            }
        }
        return false;
    }

};

int main(){
    Solution solution;
//    vector<int> A{9,9,9,9,9,9,9,9,9,9};
//    int K = 1;
//    vector<int> A{1,2,0,0};
//    int K = 34;
    vector<int> A{2,7,4};
    int K = 181;
    vector_util::print(solution.addToArrayForm(A,K));
    return 0;
}
