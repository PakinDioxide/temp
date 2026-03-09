#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;
const ll mod = 1e9+7;

int n;
vector <int> adj[mxN];
pair <ll, ll> dp[mxN];
ll fac[mxN];

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

ll inv(ll x) {
    return poww(x, mod-2);
}

ll ncr(ll x, ll y) {
    return (((fac[x] * inv(fac[y])) % mod) * inv(fac[x-y])) % mod;
}

void dfs(int u, int p) {
    vector <ll> V;
    for (auto v : adj[u]) if (v != p) {
        dfs(v, u);
        dp[u].first += dp[v].first;
        V.emplace_back(dp[v].first);
        dp[u].second *= dp[v].second; dp[u].second %= mod;
    }
    ll x = dp[u].first;
    for (auto &e : V) dp[u].second *= ncr(x, e), dp[u].second %= mod, x -= e;
    dp[u].first++;
}

ll T = 0;

void dfs2(int u, int p, ll sz, ll t) {
    // CALC for U
    ll SZ = sz + dp[u].first - 1;
    ll tt = (((ncr(SZ, sz) * t) % mod) * dp[u].second) % mod;
    T += tt, T %= mod;
    for (auto v : adj[u]) if (v != p) {
        ll nSZ = SZ - dp[v].first + 1;
        ll ntt = (((tt * inv(ncr(SZ, dp[v].first))) % mod) * inv(dp[v].second)) % mod;
        dfs2(v, u, nSZ, ntt);
    }
}

void solve() {
    cin >> n;
    // TRY N^2
    for (int i = 1; i <= n; i++) adj[i].clear(), dp[i] = {0, 1};
    T = 0;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    dfs2(1, 1, 0, 1);
    cout << (((T * inv(fac[n-1])) % mod) * inv(fac[n])) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    fac[0] = 1;
    for (int i = 1; i < mxN; i++) fac[i] = (fac[i-1] * i) % mod;
    int T; cin >> T;
    while (T--) solve();
}
