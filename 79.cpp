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
                                      {0,  -1}};
    vector<vector<char>> board;
    int column;
    int row;
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
     * @param path_len [i,j]
     * @param visit
     * @return
     */
    bool backtrack(int i, int j, int path_len, vector<vector<int>> &visit) {
        //base case
        if (this->word[path_len] != this->board[i][j]) {
            return false;
        }

        if (path_len == this->word.size() - 1) {
            return true;
        }
        for (auto &direction : directions) {

            int next_i = i + direction[0];
            int next_j = j + direction[1];

            if (next_i >= 0 && next_j >= 0 &&
                next_i <= row - 1 && next_j <= column - 1 &&
                visit[next_i][next_j] != 1) {

                visit[next_i][next_j] = 1;
                bool ret = backtrack(next_i, next_j, path_len + 1, visit);
                visit[next_i][next_j] = 0;

                if (ret) {
                    return true;
                } else {
                    continue;
                }

            } else {
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