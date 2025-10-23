/*
    author  : 
    created : 08/07/2025 07:50
    task    : CEOI09_harbingers
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n;
ll q[mxN], a[mxN], b[mxN], dp[mxN];
vector <pair <int, ll>> adj[mxN];
vector <int> iter;
int cht[mxN];

void build(int u, int p) { for (auto &[v, w] : adj[u]) if (v != p) q[v] = q[u] + w, build(v, u); }
ll calc(ll x, int j) { return -q[j]*x + dp[j]; }
long double m(int x, int y) { return (long double) (calc(0, x) - calc(0, y))/((-q[y])-(-q[x])); }
int sz = 0;

int qr(ll x) {
    int l = 0, r = sz-2, idx = sz-1;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (m(cht[mid], cht[mid+1]) <= x) l = mid+1;
        else r = mid-1, idx = mid;
    }
    return cht[idx];
}

int add(int x) {
    int l = 0, r = sz-2, idx = sz;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (m(cht[mid+1], x) <= m(cht[mid], cht[mid+1])) r = mid-1, idx = mid+1;
        else l = mid+1;
    }
    return idx;
}

void dfs(int u, int p) {
    for (auto [v, w] : adj[u]) if (v != p) {
        vector <int> del;
        int idx = qr(a[v]);
        dp[v] = calc(a[v], idx) + q[v]*a[v] + b[v];
        int ida = add(v);
        int tmp = cht[ida], tsz = sz;
        cht[ida] = v;
        sz = ida+1;
        dfs(v, u);
        cht[ida] = tmp;
        sz = tsz;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n; iter.resize(n+10); iota(iter.begin(), iter.end(), 0);
    for (int i = 1; i < n; i++) { int u, v; ll w; cin >> u >> v >> w; adj[u].emplace_back(v, w); adj[v].emplace_back(u, w); }
    build(1, 1);
    for (int i = 2; i <= n; i++) cin >> b[i] >> a[i];
    cht[0] = 1; sz++;
    dfs(1, 1);
    for (int i = 2; i <= n; i++) cout << dp[i] << ' '; cout << '\n';
}

/*
dp[i] = min(dp[j] + (p[i] - p[j])*a[i] + b[i])
      = min(dp[j] + p[i]*a[i] - p[j]*a[i] + b[i])
      = p[i]*a[i] + b[i] + min(-p[j]*a[i] + dp[j])
*/