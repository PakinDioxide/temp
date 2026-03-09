#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define int ll

using namespace std;

const int mxN = 1005;
const ll mod = 1e9+7;

int vis[mxN], g[mxN], val[mxN], deg[mxN];
vector <int> adj[mxN], adjr[mxN], gc[mxN];
multiset <int> adt[mxN];
ll dp[mxN][2];
stack <int> st;

void dfs1(int u) {
    vis[u] = 1;
    for (auto v : adj[u]) if (!vis[v]) dfs1(v);
    st.emplace(u);
}
 
void dfs2(int u, int k) {
    g[u] = k;
    gc[k].emplace_back(u);
    for (auto v : adjr[u]) if (!g[v]) dfs2(v, k);
}

void dfs3(int u) {
    vis[u] = 1;
    if (adt[u].size() == 0) dp[u][0] = dp[u][1] = 1;
    for (auto v : adt[u]) if (!vis[v]) {
        dfs3(v);
        dp[u][0] += (dp[v][0] + dp[v][1]) % mod, dp[u][0] %= mod;
        dp[u][1] += dp[v][1], dp[u][1] %= mod;
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    pair <ll, ll> a[n];
    for (auto &[x, y] : a) cin >> x >> y;
    ll d[n];
    for (int i = 0; i < n; i++) d[i] = a[i].first*a[i].first + a[i].second*a[i].second;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) {
        if (d[i] >= (a[i].first-a[j].first)*(a[i].first-a[j].first) + (a[i].second-a[j].second)*(a[i].second-a[j].second)) adj[i+1].emplace_back(j+n+1), adjr[j+n+1].emplace_back(i+1);//, cout << i+1 << ' ' << j+1 << '\n';
    }
    for (int i = 1; i <= 2*n; i++) if (!vis[i]) dfs1(i);
    int idx = 0;
    while (!st.empty()) {
        if (!g[st.top()]) dfs2(st.top(), ++idx);
        st.pop();
    }
    for (int i = 0; i <= 2*n; i++) val[i] = -1;//, cout << g[i] << ' '; cout << '\n';
    ll ans = 1;
    vector <int> kk(2*n+1);
    for (int i = idx; i >= 1; i--) {
        int k = 1, ok = 2;
        for (auto e : gc[i]) {
            e = (e > n ? e-n : e+n);
            if (val[e] != -1) { k = !val[e]; ok = 1; break; }
        }
        if (ok > 1) kk[i] = 1;
        for (auto &e : gc[i]) val[e] = k;
    }
    for (int u = 1; u <= 2*n; u++) if (kk[g[u]]) for (auto v : adj[u]) if (kk[g[v]] && g[u] != g[v]) adt[g[u]].emplace(g[v]), deg[g[v]]++;//, cout << g[u] << ' ' << g[v] << '\n';
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= 2*n; i++) if (kk[i] && !vis[i]) {
        dfs3(i);
        if (deg[i] == 0) ans *= (dp[i][0] + dp[i][1]) % mod, ans %= mod;
    }
    // for (int i = 1; i <= n; i++) cout << val[i] << ' '; cout << '\n';
    cout << (ans-1+mod) % mod << '\n';
}

/*
we can check if (x, y) can go together

if (x, y) cant go

!(x & y) = 1
!x or !y = 1

x -> y = ~x v y
x -> !y = 1
!y -> x = 1
*/