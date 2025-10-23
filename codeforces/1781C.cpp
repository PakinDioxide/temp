/*
    author  : 
    created : 30/08/2025 16:29
    task    : 1781C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map <char, int> c;
    for (auto &e : s) c[e]++;
    int mn = INT_MAX, k = -1;
    vector <pair <int, char>> cc;
    for (auto &[x, y] : c) cc.emplace_back(y, x);
    sort(cc.begin(), cc.end());
    for (int x = 1; x <= n; x++) {
        if (n % x || n/x > 26) continue;
        int s = 0;
        for (auto &[e, idk] : cc) s += max(0, e - x);
        for (int i = 0; i < (int) cc.size() - n/x; i++) s += cc[i].first;
        if (s < mn) mn = s, k = x;
    }
    map <char, int> ep, vis;
    for (auto &[x, y] : c) ep[x] = k;
    for (int i = 0; i < (int) cc.size() - n/k; i++) ep[cc[i].second] = 0;
    for (auto &[x, y] : ep) if (y) vis[x] = 1;
    int cnt = cc.size();
    for (char i = 'a'; cnt < n/k; i++) if (!vis[i]) ep[i] = k, vis[i] = 1, cnt++;
    vector <pair <char, int>> v;
    for (auto &[x, y] : ep) if (ep[x] > c[x]) v.emplace_back(x, ep[x] - c[x]);
    for (auto &e : s) {
        if (c[e] > ep[e]) {
            c[e]--;
            e = v.back().first;
            if (!(--v.back().second)) v.pop_back();
        }
    }
    cout << mn << '\n' << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}