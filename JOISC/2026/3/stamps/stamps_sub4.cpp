#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int n, d, t[mxN];
vector <int> adj[mxN];

struct SEG {
    int seg[4*mxN];
    
    void build(int l, int r, int u) {
        if (l == r) seg[u] = l;
        else {
            int m = l + (r-l)/2;
            build(l, m, u<<1);
            build(m+1, r, u<<1|1);
            seg[u] = min(seg[u<<1], seg[u<<1|1]);
        }
    }

    void upd(int l, int r, int x, int k, int u) {
        if (l == r) seg[u] += k;
        else {
            int m = l + (r-l)/2;
            if (m >= x) upd(l, m, x, k, u<<1);
            else upd(m+1, r, x, k, u<<1|1);
            seg[u] = min(seg[u<<1], seg[u<<1|1]);
        }
    }

    int qr(int l, int r, int x, int y, int k, int u) {
        if (seg[u] > k || l > y || r < x) return 0;
        if (l == r) return l;
        else {
            int m = l + (r-l)/2;
            int ans = qr(m+1, r, x, y, k, u<<1|1);
            if (ans == 0) ans = qr(l, m, x, y, k, u<<1);
            return ans;
        }
    }
} T1, T2;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    T1.build(1, n, 1);
    T2.build(1, n, 1);
    for (int i = 1; i <= n; i++) T1.upd(1, n, i, t[i], 1), T2.upd(1, n, n-i+1, t[i], 1);
    for (int i = 1; i <= n; i++) {
        if (t[i] == 0) cout << min(n, i+d) - max(1, i-d) + 1 << '\n';
        else cout << max(0, -(max(1, i-d)) + 1 + T1.qr(1, n, i-d, i, i, 1)) + max(0, -(max(1, n-i+1-d)) + 1 + T2.qr(1, n, n-i+1-d, n-i+1, n-i+1, 1)) << '\n';
    }
}
