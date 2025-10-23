/*
    author  : 
    created : 06/07/2025 21:54
    task    : 2124C
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

ll __lcm(ll x, ll y) { return x*y/__gcd(x, y); }

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    int ans = 1;
    for (int i = 0; i < n-1; i++) {
        int k = __lcm(a[i], a[i+1])/a[i+1];
        // cout << k << ' ';
        ans = __lcm(ans, k);
    }
    // cout << '\n';
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
a_i+1 = k(a_i)


*/