#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

pair <int, int> par[mxN];

int fi(int x, int T) {
    if (par[x].second > T || x == par[x].first) return x;
    else return fi(par[x].first, T);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k; cin >> n >> k;
    int q = n + k-1;
    vector <pair <int, int>> E;
    E.emplace_back(0, 0);
    for (int i = 1; i <= n; i++) par[i] = make_pair(i, 0);
    int it = 0;
    while (q--) {
        char t; cin >> t;
        if (t == 'S') {
            it++;
            int u, v; cin >> u >> v;
            assert(fi(u, it) != fi(v, it));
            par[fi(u, it)] = make_pair(fi(v, it), it);
            E.emplace_back(u, v);
        } else if (t == 'Q') {
            int u, v; cin >> u >> v;
            if (u == v) { cout << "yes\n"; continue; }
            if (fi(u, it) != fi(v, it) || v > n || v < 1) { cout << "no\n"; continue; }
            int L = 0, R = it, tt = 0;
            while (L <= R) {
                int x = L + (R-L)/2;
                if (fi(u, x) == fi(v, x)) R = x-1, tt = x;
                else L = x+1;
            }
            assert(fi(u, tt) == fi(v, tt));
            if (E[tt].first == u || E[tt].second == u) cout << "yes\n";
            else cout << "no\n";
        } else {
            int d; cin >> d;
            cout << "0\n";
        }
    }
}
