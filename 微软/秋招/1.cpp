#include "bits/stdc++.h"

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

//std::unordered_set<char>
std::unordered_map<char, int> rule{
        {'B', 1},
        {'A', 1},
        {'L', 2},
        {'O', 2},
        {'N', 1},
};
std::unordered_map<char, int> map{
        {'B', 0},
        {'A', 0},
        {'L', 0},
        {'O', 0},
        {'N', 0},
};

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int min_ = INT_MAX;
    for (auto c : S) {
        if (map.count(c)){
            map[c]++;
        }
    }

    for (auto item :map) {
        min_ = std::min(min_,item.second / rule[item.first]);
    }

    return min_;
}

int main() {
    std::string S = "BALLOONBALLOON";
    std::cout << solution(S);
}
