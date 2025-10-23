/*
    author  : PakinDioxide
    created : 06/04/2025 22:20
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int o = 1, e = 2, ok = 1;
    pair <ll, ll> ans[n];
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O') {
            ans[i] = make_pair(o, e);
            o += 2, e += 2;
        } else {
            if (o < e && o+2 <= 2*n) ans[i] = make_pair(o, o+2), o += 4;
            else ans[i] = make_pair(e, e+2), e += 4;
        }
        if (ans[i].first > 2*n || ans[i].second > 2*n || (i > 0 && ans[i].first + ans[i].second < ans[i-1].first + ans[i-1].second)) {ok = 0; break;}
    }
    if (ok == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto &[x, y] : ans) cout << x << ' ' << y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}