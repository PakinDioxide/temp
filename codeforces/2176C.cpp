#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    vector <int> E;
    int mx = -1;
    for (auto &e : a) {
        if (e % 2 == 0) E.emplace_back(e);
        else mx = max(mx, e);
    }
    sort(E.begin(), E.end());
    reverse(E.begin(), E.end());
    int sz = E.size();
    int p[sz+1]; p[0] = 0;
    for (int i = 1; i <= sz; i++) p[i] = p[i-1] + E[i-1];
    for (int k = 1; k <= n; k++) {
        if (mx == -1) { cout << 0 << ' '; }
        else if (sz == 0) { cout << mx * (k % 2) << ' '; }
        else if (sz >= k-1) { cout << mx + p[k-1] << ' '; }
        else if (k == n) { cout << (mx + p[sz]) * ((k - sz) % 2) << ' '; }
        else {
            if (k % 2 == sz % 2) cout << mx + p[sz-1] << ' ';
            else cout << mx + p[sz] << ' ';
        }
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*
0 -> o -> e -> e -> e -> ..
*/