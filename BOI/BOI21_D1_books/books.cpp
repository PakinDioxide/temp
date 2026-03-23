#include "books.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

map <int, ll> mp;

ll sk(int x) {
    if (mp[x]) return mp[x];
    return mp[x] = skim(x);
}

void solve(int N, int K, ll A, int s) {
    mp.clear();
    ll S = 0;
    vector <ll> V;
    for (int i = N; i > N-K; i--) V.emplace_back(sk(i)), S += sk(i);
    vector <int> v;
    ll L = 1;
    for (int i = 0; i < K; i++) {
        S -= V.back(); V.pop_back();
        int R = N-K+i+1;
        int idx = -1;
        if (L > R) impossible(); 
        while (L <= R) {
            int x = L + (R-L)/2;
            if (sk(x) + S >= A) idx = x, R = x-1;
            else L = x+1;
        }
        if (idx == -1) impossible();
        v.emplace_back(idx);
        L = idx;
    }
    S = 0;
    for (auto &e : v) S += sk(e);
    if (!(S >= A && S <= 2*A)) impossible();
    answer(v);
}
