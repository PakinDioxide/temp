#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[200005];
int st[200005], en[200005], n, q, cnt = 0;
ll a[200005], fen[200005];

void add(int idx, ll x) {
    for (int i = idx; i <= n; i += i & (-i)) fen[i] += x;
}

ll sum(int idx) {
    ll k = 0;
    for (int i = idx; i > 0; i -= i & (-i)) k += fen[i];
    return k;
}

void dfs(int u, int p) {
    st[u] = ++cnt;
    add(st[u], a[u]);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    en[u] = cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    dfs(1, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            add(st[s], x-a[s]);
            a[s] = x;
        } else {
            int s;
            cin >> s;
            cout << sum(en[s]) - sum(st[s]-1) << '\n';
        }
    }
}