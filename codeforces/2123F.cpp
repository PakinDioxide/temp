/*
    author  : 
    created : 01/07/2025 23:21
    task    : 2123F
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

vector <ll> prime;

bool is_prime(ll x) {
    if (x <= 1) return 0;
    if (x == 2) return 1;
    for (auto &e : prime) {
        if (x % e == 0) return 0;
        if (e * e > x) break;
    }
    return 1;
}

void solve() {
    int n; cin >> n;
    int ans[n], vis[n+1]; memset(vis, 0, sizeof(vis));
    ans[0] = 1;
    int idx = upper_bound(prime.begin(), prime.end(), n) - prime.begin() - 1;
    for (int i = idx; i >= 0; i--) {
        int e = prime[i];
        vector <int> v;
        for (int i = e; i <= n; i += e) if (!vis[i] && i % e == 0) vis[i] = 1, v.emplace_back(i);
        for (int i = 0; i < v.size(); i++) ans[v[(i == 0 ? v.size()-1 : i-1)] - 1] = v[i];
    }
    for (auto &e : ans) cout << e << ' '; cout << '\n';
    // for (int i = 0; i < n; i++) if (i+1 == ans[i]) cout << i+1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i <= 100000; i++) if (is_prime(i)) prime.emplace_back(i);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
    1 must be at index 1
    prime must be at multiple of primes
*/