#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    int a[n]; for (auto &e : a) cin >> e, e--;
    int id[n]; for (int i = 0; i < n; i++) id[a[i]] = i;
    int b[m]; for (auto &e : b) cin >> e, e--, e = id[e];
    set <int> ap[n];
    for (auto &e : ap) e.emplace(INT_MAX);
    for (int i = 0; i < m; i++) ap[b[i]].emplace(i);
    set <int> clf;
    for (int i = 0; i < n-1; i++) if (*ap[i].begin() > *ap[i+1].begin()) clf.emplace(i);
    if (clf.empty()) cout << "YA\n";
    else cout << "TIDAK\n";
    while (q--) {
        int x, y; cin >> x >> y; x--; y--; y = id[y];
        ap[b[x]].erase(ap[b[x]].find(x));
        if (b[x] > 0) {
            if (*ap[b[x]].begin() < *ap[b[x]-1].begin()) clf.emplace(b[x]-1);
            else if (clf.find(b[x]-1) != clf.end()) clf.erase(clf.find(b[x]-1));
        }
        if (b[x] < n-1) {
            if (*ap[b[x]].begin() > *ap[b[x]+1].begin()) clf.emplace(b[x]);
            else if (clf.find(b[x]) != clf.end()) clf.erase(clf.find(b[x]));
        }
        b[x] = y;
        ap[b[x]].emplace(x);
        if (y > 0) {
            if (*ap[y].begin() < *ap[y-1].begin()) clf.emplace(y-1);
            else if (clf.find(y-1) != clf.end()) clf.erase(clf.find(y-1));
        }
        if (y < n-1) {
            if (*ap[y].begin() > *ap[y+1].begin()) clf.emplace(y);
            else if (clf.find(y) != clf.end()) clf.erase(clf.find(y));
        }
        if (clf.empty()) cout << "YA\n";
        else cout << "TIDAK\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}