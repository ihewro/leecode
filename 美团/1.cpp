//
// Created by hewro on 2021/3/27.
//

#include "bits/stdc++.h"
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)cin >> arr[i];
        int start = 0, end = n - 1;
        vector<int> tmp;
        while (start <= end) {
            if (arr[start] != arr[end])tmp.push_back(start);
            ++start;
            --end;
        }
        if (tmp.size() == 0) {
            if (n % 2 != 0)arr[n / 2] = 0;
        } else if (tmp.size() == 1) {
            int t = min(arr[tmp[0]], arr[n - 1 - tmp[0]]);
            arr[tmp[0]] = t;
            arr[n - 1 - tmp[0]] = t;
        } else {
            for (int i = 0; i < n; ++i)
                if (arr[i] != 0) {
                    arr[i] = 0;
                    break;
                }
        }
        for (int i = 0; i < n; ++i)
            cout << arr[i];
        cout << endl;
    }
    return 0;
    union MyUnion{
        int a;
        char c;
    }test;
    test.a = 1;
    if (test.c == 1)
        cout << "little endian" <<endl;
    else cout << "big endian" <<endl;
}