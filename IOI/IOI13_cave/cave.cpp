#include "cave.h"
#include <bits/stdc++.h>

using namespace std;

int n;

int ask(int a[]) {
    int k = tryCombination(a);
    return (k == -1 ? n : k);
}

void exploreCave(int N) {
    n = N;
    set <int> s; for (int i = 0; i < n; i++) s.emplace(i);
    vector <pair <int, int>> v;
    function <int(int, int, int, int)> sol = [&] (int k, int l, int r, int val) {
        if (l == r) {
            auto it = s.begin();
            for (int i = 0; i < l; i++) it = next(it);
            return *it;
        }
        int q[n]; for (auto &e : q) e = !val;
        for (auto &[x, y] : v) q[x] = y;
        auto it = s.begin();
        int m = l + (r-l)/2;
        for (int i = 0; i < l; i++) it = next(it);
        for (int i = l; i <= m; i++) q[*it] = val, it = next(it);
        // cout << l << ' ' << r << '\n';
        // for (auto &e : q) cout << e << ' '; cout << '\n';
        if (ask(q) >= k) return sol(k, l, m, val);
        else return sol(k, m+1, r, val);
    };
    for (int i = 0; i < n; i++) {
        int A[n], B[n]; for (auto &e : A) e = 0; for (auto &e : B) e = 0;
        for (auto &[x, y] : v) A[x] = y, B[x] = y;
        int p = ask(A);
        int idx = -1;
        if (p >= i+1) v.emplace_back(idx = sol(i+1, 0, (int) s.size()-1, 0), 0);
        else v.emplace_back(idx = sol(i+1, 0, (int) s.size()-1, 1), 1);
        s.erase(s.find(idx));
        // cout << i << ' ' << idx << ' ' << !(p == -1 || p == i+1) << '\n';
    }
    int a1[n], a2[n];
    for (int i = 0; i < n; i++) a1[v[i].first] = v[i].second, a2[v[i].first] = i;
    answer(a1, a2);
}

/*
must do O(NlogN)
*/
