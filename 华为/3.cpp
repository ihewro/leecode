//
// Created by hewro on 2021/10/13.
//
#include "bits/stdc++.h"

using namespace std;

function encode (str) {
    const l = []
    let i = 0
    for (const s of str) {
        const len = l.length
        const lastChar = len > 0 ? l[len - 1][0] : undefined
        if (lastChar === s) {
            l[len - 1][1]++
        } else {
            l.push([s, 1])
        }
    }
    return l.map(x => x.join('')).join('')
}

int main (){
    string s; cin >> s;

    int left= 0 , right = 0;
    while (right < s.size()){

    }
}