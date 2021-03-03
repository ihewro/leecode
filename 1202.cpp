/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/1/11
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */
#include "Util.hpp"
#include "UF.hpp"
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UF uf(s.size());
        for (auto  pair: pairs){
            uf.union_node(pair[0],pair[1]);
        }

        //森林中每棵树拿出来放到一个有序set中
        std::unordered_map<int,std::list<char>> root_map;
        for (int i = 0; i < s.size(); ++i) {
            int root = uf.find(i);
//            std::cout <<"node:" << i << "root:" << root << std::endl;
            if (root_map.count(root) > 0){
                auto current = s.at(i);
                auto front_ = root_map[root].front();
                auto end_ = root_map[root].back();
                if (current <= front_){
                    root_map[root].push_front(current);
                }else if (current >= end_){
                    root_map[root].push_back(current);
                }else{
                    //找到插入的位置
                    auto begin_ = root_map[root].begin();
                    auto begin_2 = (++root_map[root].begin());
                    while (begin_2 != root_map[root].end()){
                        if (current >= *(begin_) && current <= *(begin_2)){
                            root_map[root].insert(begin_2,current);
                            break;
                        }else{
                            begin_++;
                            begin_2++;
                        }
                    }
                }
            }else{
                root_map[root] = std::list<char>{s.at(i)};
            }
        }


        //遍历整个字符串，重组字符串
        for (int i = 0; i < s.size(); ++i) {
            int root = uf.find(i);
            s.at(i) = root_map[root].front();
            root_map[root].pop_front();
        }
        return s;
    }
};

int main(){
    Solution solution;
    string s = "pwqlmqm";
    vector<vector<int>> input = {{5,3},{3,0},{5,1},{1,1},{1,5},{3,0},{0,2}};
//    string s = "da";
//    vector<vector<int>> input = {{0,1}};
//    string s = "dcab";
//    vector<vector<int>> input = {{0,3},{1,2},{0,2}};

//    string s = "qdwyt";
//    vector<vector<int>> input = {{2,3},{3,2},{0,1},{4,0},{3,2}};


//    std::list<char> test{};
//    test.push_back('a');
//    test.push_back('c');
//
//    for (auto item:test){
//        std::cout << item << ",";
//    }

    std::cout << solution.smallestStringWithSwaps(s,input) << std::endl;
}