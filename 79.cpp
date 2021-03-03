/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/6
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include <utility>

#include "Util.hpp"

class Solution {
public:
    string word;
    vector<vector<int>> directions = {{1,  0},
                                      {0,  1},
                                      {-1, 0},
                                      {0,  -1}};//下，右，上，左
    vector<vector<char>> board;
    int column;//列
    int row;//行
//    int find_index = 0;
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty()) {
            return false;
        }
        this->word = std::move(word);
        this->row = board.size();
        this->column = board[0].size();
        vector<vector<int>> visit(row, vector<int>(column, 0));
        this->board = std::move(board);

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
//                if ((row - 1 - i) * column + (column - j) < this->word.size()) {
//                    //从这开始后面就算全部匹配上了，结果都是false
//                    return false;
//                }

                visit[i][j] = 1;
                if (backtrack(i, j, 0, visit)) {
                    return true;
                }
                visit[i][j] = 0;
            }
        }

        return false;
    }

    /**
     *
     * @param i
     * @param j
     * @param path_len [i,j]对应 word 可能匹配的位置
     * @param visit
     * @return
     */
    bool backtrack(int i, int j, int path_len, vector<vector<int>> &visit) {
        //base case
        if (this->word[path_len] != this->board[i][j]) {
            return false;
        }

        if (path_len == this->word.size() - 1) {//最后一个元素
            return true;
        }

//        if ((i == row - 1 && j == column - 1)) {
//            return false;
//        }

        //选择空间
        for (auto &direction : directions) {

            //回溯
            int next_i = i + direction[0];
            int next_j = j + direction[1];

            if (next_i >= 0 && next_j >= 0 &&
                next_i <= row - 1 && next_j <= column - 1 &&
                visit[next_i][next_j] != 1) {//下一个相邻节点存在，而且没有访问过

                visit[next_i][next_j] = 1;
                bool ret = backtrack(next_i, next_j, path_len + 1, visit);
                //撤销选择
                visit[next_i][next_j] = 0;

                if (ret) {//当前元素及其后续的元素匹配上了
                    return true;
                } else {//继续找下一个相邻的子节点
                    continue;
                }

            } else {//继续找下一个相邻的子节点
                continue;
            }

        }

        return false;

    }

};

int main() {
    Solution solution;
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};

    string word = "SEE";

    std::cout << solution.exist(board, word);
}