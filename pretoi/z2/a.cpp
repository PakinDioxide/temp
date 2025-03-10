#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) a[i] = 1;
    vector <tuple <int, int, int, int, int>> v; // idx, add [1] or remove [0], value, id, min [1] or max [0]
    for (int i = 0; i < q; i++) {
        int l, r, k, c;
        cin >> l >> r >> k >> c;
        v.emplace_back(l, 1, (c == 0 ? k : k-1), i, !c);
        v.emplace_back(r+1, 0, 0, i, !c);
    }
    sort(v.begin(), v.end());
    int v_i = 0, ok = 1;
    vector <pair <int, int>> mn, mx;
    for (int i = 0; i <= n; i++) {
        while (v_i < v.size() && get<0>(v[v_i]) == i) {
            auto [idx, t, val, id, mm] = v[v_i];
            if (t == 1) {
                if (mm) mn.emplace_back(val, id);
                else mx.emplace_back(val, id);
            } else {
                if (mm) for (int j = 0; j < mn.size(); j++) {if (mn[j].second == id && mn[j].first > 0) ok = 0;}
                else for (int j = 0; j < mx.size(); j++) {if (mx[j].second == id) mx[j].first = n;}
            }
            v_i++;
        }
        if (i == n) break;
        int mmx = n, mmn = 0;
        for (auto e : mx) mmx = min(mmx, e.first);
        for (auto e : mn) mmn = max(mmn, e.first);
        if (mmx && mmn) {
            a[i] = 0;
            for (auto &e : mn) e.first--;
            for (auto &e : mx) e.first--;
        }
    }
    if (!ok) cout << -1 << '\n';
    else {for (auto e : a) cout << e << ' '; cout << '\n';}
}