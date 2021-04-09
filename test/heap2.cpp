#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int N = 100010;
int h[N], size_;

void down(int u) {
    int t = u;  // t记录最小值
    if (2 * u <= size_ && h[2 * u] < h[t]) t = 2 * u; // 左儿子存在，且值比父亲小
    if (2 * u + 1 <= size_ && h[2 * u + 1] < h[t]) t = 2 * u + 1; // // 右儿子存在，且值比父亲小
    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
    return;
}

void up(int u) {
    if (u / 2 > 0 && h[u / 2] > h[u]) {
        swap(h[u / 2], h[u]);
        up(u / 2);
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    size_ = n;

    // 初始化堆
    for (int i = n / 2; i > 0; i --) down(i);

    for (int i = 1; i <= n; ++i) {
        cout << h[i] << " ";
    }
//    while(n --) {
//        cout << h[1] << " ";
//        h[1] = h[size_];
//        size_ --;
//        down(1);
//    }

    return 0;
}
