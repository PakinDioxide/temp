#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct Line {
    ll m, c;
    ll operator()(ll x) { return m*x + c; }
};

struct Node {
    Line val;
    int l, r;
};

Node pool[mxN<<5];
int it = 0;

int nw(Line x = {0, LLONG_MAX}) {
    pool[++it] = {x, 0, 0};
    return it;
}

struct LC {
    vector <Line> v;
    int root = nw();
    void ins(int l, int r, Line x, int u) {
        if (l == -1e5 && r == 1e5) v.emplace_back(x);
        if (l == r) {
            if (pool[u].val(l) > x(l)) pool[u].val = x;
            return;
        }
        int m = l + (r-l)/2;
        if (x.m > pool[u].val.m) swap(x, pool[u].val);
        if (x(m) < pool[u].val(m)) {
            swap(x, pool[u].val);
            if (pool[u].l == 0) pool[u].l = nw();
            ins(l, m, x, pool[u].l);
        } else {
            if (pool[u].r == 0) pool[u].r = nw();
            ins(m+1, r, x, pool[u].r);
        }
    }
    ll qr(int l, int r, int x, int u) {
        if (l == r) return pool[u].val(x);
        else {
            int m = l + (r-l)/2;
            if (m >= x) {
                if (pool[u].l == 0) pool[u].l = nw();
                return min(pool[u].val(x), qr(l, m, x, pool[u].l));
            } else {
                if (pool[u].r == 0) pool[u].r = nw();
                return min(pool[u].val(x), qr(m+1, r, x, pool[u].r));
            }
        }
    }
} seg[(int) 1e5+5];

ll dp[(int) 1e5+5], a[(int) 1e5+5], b[(int) 1e5+5];
vector <int> adj[(int) 1e5+5];

void dfs(int u, int p) {
    int cnt = 0;
    dp[u] = LLONG_MAX;
    for (auto v : adj[u]) if (v != p) {
        cnt++;
        dfs(v, u);
        if (seg[v].v.size() > seg[u].v.size()) swap(seg[u], seg[v]);
        for (auto &x : seg[v].v) seg[u].ins(-1e5, 1e5, x, seg[u].root);
    }
    if (cnt == 0) dp[u] = 0;
    else dp[u] = seg[u].qr(-1e5, 1e5, a[u], seg[u].root);
    seg[u].ins(-1e5, 1e5, {b[u], dp[u]}, seg[u].root);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    for (int i = 1; i <= n; i++) cout << dp[i] << ' '; cout << '\n';
}

/*
dp[i] = min(b[j](a[i]) + dp[j]) -- CHT
- arbitary query & slope -> lichao bruh
*/
