#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, m;

pair <int, int> nex(int l, pair <int, int> idx) {
    if (idx.first == l) {
        idx.second++;
        if (idx.second == m-l) idx.first++, idx.second--;
    } else if (idx.first == n-l-1) {
        idx.second--;
        if (idx.second == l-1) idx.first--, idx.second++;
    } else if (idx.second == m-l-1) {
        idx.first++;
    } else {
        idx.first--;
    }
    return idx;
}

void solve() {
    cin >> n >> m;
    int a[n][m], val[4] = {1, 5, 4, 3};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
    }
    ll cnt = 0;
    for (int l = 0; l < min(m, n)/2; l++) {
        pair <int, int> idx[4], st = {l, l};
        idx[0] = {l, l};
        for (int i = 1; i < 4; i++) idx[i] = nex(l, idx[i-1]);
        do {
            // cout << idx[0].first << ' ' << idx[0].second << '\n';
            int ok = 1;
            for (int j = 0; j < 4; j++) if (a[idx[j].first][idx[j].second] != val[j]) {ok = 0; break;}
            cnt += ok;
            for (int j = 0; j < 3; j++) idx[j] = idx[j+1];
            idx[3] = nex(l, idx[3]);
        } while (idx[0] != st);
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}