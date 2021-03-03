/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/9
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include "../Utils/Util.hpp"

class Solution {
public:

    std::unordered_map<std::string,int>memo;

    int maxProfit(vector<int>& prices) {
//        memset(memo, -1, sizeof(int)*100000);//�����100001�������С����Ҫ�����滻�¾Ϳ����ˡ�
        return dp_helper(prices,0,0,2);
    }
    /**
     *
     * @param begin �ڼ��쿪ʼ
     * @param isHave ��ǰ�Ƿ�ӵ�й�Ʊ
     * @param times ʣ��Ŀ������Ʊ�Ĵ���
     * @return
     */
    int dp(vector<int>& prices,int begin,bool isHave,int times){
        //base case
        if (begin == prices.size() - 1){//���һ�������û�н��״�����
             return isHave ? prices[begin] : 0;
        }

//        if (times == 0){//���״���Ϊ0
//            if (isHave){//���й�Ʊ�����ֵΪ����֮��Ĺɼ۵����ֵ
//                int max = 0 ;
//                for (int i = begin; i < prices.size() ;i++){
//                    if (prices[i] > max){
//                        max = prices[i];
//                    }
//                }
//                return max;
//            }else{//�����й�Ʊ�����ֵΪ0
//                return 0;
//            }
//        }

        //�ݹ��������еļ�ֵ
        if (isHave){
            //����ѡ�񲻲�������������Ʊ
            return std::max(
                    dp_helper(prices,begin+1, 1, times),
                    dp_helper(prices,begin+1, 0, times) + prices[begin]
                    );
        }else{
            //����ѡ�������Ʊ���߲�����
            if (times > 0){//����ѡ�����룬���߲�����
                return std::max(
                        dp_helper(prices,begin+1,1,times-1) - prices[begin],
                        dp_helper(prices,begin+1,0,times)
                        );
            }else{
                return dp_helper(prices,begin+1,0,0);
            }
        }
    }

    int dp_helper(vector<int>& prices,int begin,int isHave,int times){
        auto key = generateKey(begin,isHave,times);
        if (memo.count(key) > 0){//��ѯ����¼
            std::cout <<"get memo" << std::endl;
            return memo[key];
        }
        int ret = dp(prices,begin,isHave,times);
        memo[key] = ret;
        return ret;
    }

    static std::string putValue(int begin, int isHave, int times){
//        int key=  std::stoi(std::to_string(begin) + std::to_string(isHave) + std::to_string(times));
        return std::to_string(begin) + std::to_string(isHave) + std::to_string(times);
//        return key;
    }
};

int main(){
    Solution solution;
    std::vector<int> input{1,3,2,4,7};
//    std::vector<int> input{1};
    std::cout << solution.maxProfit(input) << std::endl;
}