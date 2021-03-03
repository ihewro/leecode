/**
 * Copyright (c) 2020, SeekLoud Team.
 * Date: 2021/2/6
	* Main Developer: hewro
	* Developer:
 * Description: 
 * Refer:
 */

#include <utility>

#include "../Utils/Util.hpp"

class Solution {
public:
    string word;
    vector<vector<int>> directions = {{1,  0},
                                      {0,  1},
                                      {-1, 0},
                                      {0,  -1}};//�£��ң��ϣ���
    vector<vector<char>> board;
    int column;//��
    int row;//��
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
//                    //���⿪ʼ�������ȫ��ƥ�����ˣ��������false
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
     * @param path_len [i,j]��Ӧ word ����ƥ���λ��
     * @param visit
     * @return
     */
    bool backtrack(int i, int j, int path_len, vector<vector<int>> &visit) {
        //base case
        if (this->word[path_len] != this->board[i][j]) {
            return false;
        }

        if (path_len == this->word.size() - 1) {//���һ��Ԫ��
            return true;
        }

//        if ((i == row - 1 && j == column - 1)) {
//            return false;
//        }

        //ѡ��ռ�
        for (auto &direction : directions) {

            //����
            int next_i = i + direction[0];
            int next_j = j + direction[1];

            if (next_i >= 0 && next_j >= 0 &&
                next_i <= row - 1 && next_j <= column - 1 &&
                visit[next_i][next_j] != 1) {//��һ�����ڽڵ���ڣ�����û�з��ʹ�

                visit[next_i][next_j] = 1;
                bool ret = backtrack(next_i, next_j, path_len + 1, visit);
                //����ѡ��
                visit[next_i][next_j] = 0;

                if (ret) {//��ǰԪ�ؼ��������Ԫ��ƥ������
                    return true;
                } else {//��������һ�����ڵ��ӽڵ�
                    continue;
                }

            } else {//��������һ�����ڵ��ӽڵ�
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