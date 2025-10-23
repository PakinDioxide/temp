/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#include "garden.h"
#define ll long long

using namespace std;

int findMinimumTime(int n, int m) {
    vector <pair <int, int>> ws;
    string s = "";
    for (int i = 0; i < m; i++) s = s + '0';
    for (int i = 0; i < m; i++) s[i] = '1', ws.emplace_back(askInw(s), i), s[i] = '0';
    sort(ws.begin(), ws.end());
    int r = 0;
    string k = s;
    for (auto &[w, idx] : ws) {
        k[idx] = '1';
        int nw = askInw(k);
        int diff = nw - r;
        if (diff != w) k[idx] = '0';
        else r = nw;
    }
    return r;
}

