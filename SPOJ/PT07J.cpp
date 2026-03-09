#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

struct Wavelet {
    vector <int> p;
    Wavelet *l, *r;
    void build(int b, const vector <int> &A) {
        if (b == 0 || A.empty()) return;
        vector <int> L, R;
        int c = 0;
        for (auto &e : A) {
            if (e & (1 << (b-1))) R.emplace_back(e);
            else c++, L.emplace_back(e);
            p.emplace_back(c);
        }
        l = new Wavelet();
        r = new Wavelet();
        l->build(b-1, L);
        r->build(b-1, R);
    }
    int qr(int b, int l, int r, int k) { // [l, r), k, 0 indexed;
        if (b == 0 || p.empty()) return 0;
        int pl = (l > 0 ? p[l-1] : 0);
        int pr = (r > 0 ? p[r-1] : 0);
        int cnt = pr - pl;
        if (cnt > k) return this->l->qr(b-1, pl, pr, k);
        else return (1 << (b-1)) + this->r->qr(b-1, l-pl, r-pr, k-cnt);
    }
};

int n, a[mxN], it = -1, st[mxN], en[mxN];
vector <int> adj[mxN], A;

void dfs(int u, int p) {
    st[u] = ++it;
    A.emplace_back(a[u]);
    for (auto v : adj[u]) if (v != p) dfs(v, u);
    en[u] = it;
}

Wavelet *w = new Wavelet();
unordered_map <int, int> id;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], id[a[i]] = i;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    dfs(1, 1);
    w->build(30, A);
    int q; cin >> q;
    while (q--) {
        int x, k; cin >> x >> k;
        cout << id[w->qr(30, st[x], en[x]+1, k-1)] << '\n';
    }
}