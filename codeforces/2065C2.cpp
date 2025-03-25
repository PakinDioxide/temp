/*
    author  : PakinDioxide
    created : 11/03/2025 16:05
    task    : 2065C2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    ll a[n], b[m];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    sort(b, b+m);
    a[0] = min(b[0]-a[0], a[0]);
    int ok = 1;
    for (int i = 1; i < n; i++) {
        int idx = lower_bound(b, b+m, a[i] + a[i-1]) - b;
        if (idx == m && a[i] < a[i-1]) {ok = 0; break;}
        if (idx == m) continue;
        else if (a[i] >= a[i-1]) a[i] = min(a[i], b[idx] - a[i]);
        else a[i] = b[idx] - a[i];
    }
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
we want b[j] - a[i] >= a[i-1]
b[j] >= a[i] + a[i-1]
*/