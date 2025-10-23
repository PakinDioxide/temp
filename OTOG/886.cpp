/*
    author  : PakinDioxide
    created : 17/04/2025 17:06
    task    : 886
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

map <int, int> mp;
multiset <int> s;

bool usePakpim(int x) {
    s.emplace(x);
    return mp[x]++;
}

int usePeteza() {
    if (s.empty()) return INT_MAX;
    int k = *(prev(s.end()));
    s.erase(prev(s.end()));
    mp[k]--;
    return k;
}

int useBlackslex() {
    if (s.empty()) return INT_MIN;
    int k = *(s.begin());
    s.erase(s.begin());
    mp[k]--;
    return k;
}