/*
    author  : PakinDioxide
    created : 22/09/2025 17:57
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, C; cin >> n >> m >> C;
    vector <int> H(m+1), co(m+1);
    iota(H.begin(), H.end(), 0);
    fill(co.begin(), co.end(), 1);
    function <int(int)> fiH = [&] (int x) {
        if (x == H[x]) return x;
        return H[x] = fiH(H[x]);
    };
    int a[m][n];
    for (auto &E : a) for (auto &e : E) cin >> e;
    for (int i = 0; i < m; i++) for (int j = i+1; j < m; j++) {
        vector <int> par(n+1), co2(n+1);
        iota(par.begin(), par.end(), 0);
        fill(co2.begin(), co2.end(), 1);
        function <int(int)> fi = [&] (int x) {
            if (x == par[x]) return x;
            return par[x] = fi(par[x]);
        };
        // for (int k = 0; k < n; k++) {
        //     int u = a[i][k], v = a[j][k];
        //     if (fi(u) != fi(v)) {
        //         co2[fi(v)] += co2[fi(u)];
        //         par[fi(u)] = fi(v);
        //     }
        // }
        for (int k = 1; k <= n; k++) if (fi(k) == k && co2[k] <= C) {
            if (fiH(i) != fiH(j)) {
                // co[fiH(j)] += co[fiH(i)];
                // H[fiH(i)] = fiH(j);
                // cout << i << ' ' << j << '\n';
            }
            break;
        }
    }
    vector <int> ans;
    for (int i = 0; i < m; i++) if (fiH(i) == i) ans.emplace_back(co[i]);
    sort(ans.begin(), ans.end());
    for (auto &e : ans) cout << e << ' ';
}