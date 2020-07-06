//
// Created by miaochl on 2020-06-30.
//

#include "Util.h"

// 1.采用排序的方法
bool Solution::isAnagram_1(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

// 2.采用哈希表法
bool Solution::isAnagram_2(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<int, int> umap;
    for (int i = 0; i < s.size(); i++) {
        ++umap[s[i]];
        --umap[t[i]];
    }

    for (auto c : umap) {
        if (c.second != 0) {
            return false;
        }
    }
    return true;
}