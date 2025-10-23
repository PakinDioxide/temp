#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> route(int n, vector<int> w) {
    int m = w.size();
    vector <pair <int, int>> e;
    int mx = 0, cyc = m-n+2, u = 1, v = 2;
    for (int i = 0; i < cyc; i++) {
        mx = max(mx, v);
        e.emplace_back(u++, v);
        if (u == v) u = 1, v++, cyc++;
    }
    for (int i = mx+1; i <= n; i++) e.emplace_back(1, i);
    return e;
}