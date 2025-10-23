/*
    author  : 
    created : 21/06/2025 21:49
    task    : 2120C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n; ll m; cin >> n >> m;
    if (m < n || m > n*(n+1)/2) { cout << -1 << '\n'; return; }
    ll val[n+1], lf = m, rt = -1;
    for (ll i = 1; i <= n; i++) {
        val[i] = max(1LL, min((ll) i, lf - (n-i)));
        lf -= val[i];
        rt = max(rt, val[i]);
    }
    cout << rt << '\n';
    for (ll i = 1; i <= n; i++) if (i != rt) cout << i << ' ' << (i == val[i] ? rt : val[i]) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
maximum is n*(n+1)/2

each node can choose it's value <= x

root must be the value n
*/