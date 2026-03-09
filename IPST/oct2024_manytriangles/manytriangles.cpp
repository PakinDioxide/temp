#include "manytriangles.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N, C;
vector <pair <ll, ll>> A;
ll ans = LLONG_MAX;
int sz = 0;
vector <pair <ll, ll>> V[8];

void bf(int idx) {
    if (idx == N) {
        ll sum = 0;
        for (int i = 0; i < C; i++) {
            ll s = 0;
            assert(V[i].size() == 3);
            for (int j = 0; j < 3; j++) {
                int k = (j + 1) % 3;
                s += V[i][j].first * V[i][k].second - V[i][j].second * V[i][k].first;
            }
            sum += abs(s);
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = sz; i < C; i++) {
        V[i].emplace_back(A[idx]);
        int cg = 0;
        if (V[i].size() == 3) swap(V[i], V[sz]), sz++, cg = 1;
        bf(idx+1);
        if (cg) sz--, swap(V[i], V[sz]);
        V[i].pop_back();
        if (V[i].empty()) break;
    }
}

long long mincost_color(int Cs, vector<int> xs, vector<int> ys) {
    C = Cs;
    N = 3*C;
    for (int i = 0; i < N; i++) A.emplace_back(xs[i], ys[i]);
    bf(0);
    return ans;
}
