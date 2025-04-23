/*
    author  : PakinDioxide
    created : 08/04/2025 22:45
    task    : 2093F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> m >> n;
    string a[m], b[n][m];
    int cnt[n], mx = 0, idx = 0;
    memset(cnt, 0, sizeof(cnt));
    for (auto &e : a) cin >> e;
    for (int i = 0; i < n; i++) {
        for (auto &e : b[i]) cin >> e;
        for (int j = 0; j < m; j++) cnt[i] += (a[j] == b[i][j]);
        if (cnt[i] > mx) mx = cnt[i], idx = i;
    }
    int c = m;
    for (int i = 0; i < m; i++) {
        if (b[idx][i] == a[i]) continue;
        int ok = 0;
        for (int j = 0; j < n; j++) {
            if (b[j][i] == a[i]) {ok = 1; break;}
        }
        if (!ok) {cout << -1 << '\n'; return;}
        c+=2;
    }
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}