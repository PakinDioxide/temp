#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[200005];
ll a[200005], st[200005], en[200005], fen[200005], idx = 0, n, q;

void add(int idx, ll x) {
    for (int i = idx; i <= n; i += i & (-i)) fen[i] += x;
}

ll sum(int idx) {
    ll k = 0;
    for (int i = idx; i > 0; i -= i & (-i)) k += fen[i];
    return k;
}

void euler(int u, int p) {
    st[u] = ++idx;
    add(st[u], sum(st[p]) + a[u]);
    add(st[u]+1, -(sum(st[p]) + a[u]));
    for (int v : adj[u]) {
        if (v == p) continue;
        euler(v, u);
    }
    en[u] = idx;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
    euler(1, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll s, x;
            cin >> s >> x;
            add(st[s], x-a[s]);
            add(en[s]+1, -(x-a[s]));
            a[s] = x;
        } else {
            int s;
            cin >> s;
            cout << sum(st[s]) << '\n';
        }
    }
}