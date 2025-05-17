// #include <bits/stdc++.h>
// #define ll long long

// using namespace std;

// const int mxN = 1e5+5;

// int n, m, par[2*mxN];
// tuple <int, int, int> E[2*mxN];
// vector <int> V;

// int fi(int x) { return x == par[x] ? x : par[x] = fi(par[x]); }

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0);
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++) cin >> get<0>(E[i]) >> get<1>(E[i]) >> get<2>(E[i]);
    
//     // BRUTE FORCE N^2 ( SUB 1 )
//     // for (int i = 1; i <= m; i++) {
//     //     iota(par, par+2*n+5, 0);
//     //     for (int j = 1; j <= m; j++) {
//     //         auto [u, v, t] = E[j];
//     //         if (i == j) continue;
//     //         if (t == 0) par[fi(u)] = fi(v), par[fi(u+n)] = fi(v+n);
//     //         else par[fi(u)] = fi(v+n), par[fi(u+n)] = fi(v);
//     //     }
//     //     int ok = 1;
//     //     for (int j = 1; j <= n; j++) if (fi(j) == fi(j+n)) { ok = 0; break; }
//     //     if (ok) V.emplace_back(i);
//     // }
//     // if (V.empty()) cout << -1 << '\n';
//     // else {
//     //     cout << V.size() << '\n';
//     //     for (auto &e : V) cout << e << ' ';
//     //     cout << '\n';
//     // }


// }

#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, m, par[2*mxN], cmp = 0;
vector <pair <int, int>> adj[2*mxN];
tuple <int, int, int> E[2*mxN];

int fi(int x) { return x == par[x] ? x : par[x] = fi(par[x]); }

void mg(int u, int v, int t) {
    par[fi(u)] = fi(v);
    adj[u].emplace_back(v, t);
    adj[v].emplace_back(u, t);
}

int lo[2*mxN], id[2*mxN], onst[2*mxN], idx = 0, vis[2*mxN];
stack <int> st;

void dfs(int u, int p) {
    lo[u] = id[u] = ++idx;
    onst[u] = 1;
    st.emplace(u);
    for (auto [v, w] : adj[u]) {
        if (!id[v] && vis[w]) continue;
        vis[w] = 1;
        if (!id[v]) dfs(v, u);
        lo[u] = min(lo[u], lo[v]);
    }
    if (lo[u] == id[u]) {
        while (!st.empty()) {
            if (onst[st.top()]) lo[st.top()] = lo[u];
            onst[st.top()] = 0;
            if (st.top() == u) {st.pop(); break;}
            st.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    iota(par, par+2*n+5, 0);
    for (int i = 1; i <= m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        E[i] = {u, v, t};
        if (t == 0) mg(u, v, i), mg(u+n, v+n, i);
        else mg(u+n, v, i), mg(u, v+n, i);
    }
    for (int e = 1; e <= n; e++) if (!lo[e]) dfs(e, e);
    set <int> v;
    for (int i = 1; i <= n; i++) if (fi(i) == fi(n+i)) v.emplace(fi(i));
    if (v.size() > 1) { cout << -1; return 0; }
    else if (v.size() == 0) { cout << m << '\n'; for (int i = 1; i <= m; i++) cout << i << ' '; cout << '\n'; return 0; }
    cmp = *v.begin();
    vector <int> C;
    for (int i = 1; i <= n; i++) if (fi(i) == cmp) C.emplace_back(i);
    int vis[mxN];
    memset(vis, 0, sizeof(vis));
    for (auto &e : C) {
        stack <int> st;
        
    }
    
    // set <int> v;
    // for (int i = 1; i <= n; i++) if (fi(i) == fi(n+i)) v.emplace(fi(i));
    // if (v.size() > 1) { cout << -1; return 0; }
    // else if (v.size() == 0) { cout << m << '\n'; for (int i = 1; i <= m; i++) cout << i << ' '; cout << '\n'; return 0; }
    // cmp = *v.begin();
    // vector <int> C;
    // for (int i = 1; i <= n; i++) if (fi(i) == cmp) C.emplace_back(i);
    // for (auto &e : C) if (!lo[e]) dfs(e, e);
    // int ok = 1;
    // for (int i = 1; i <= n; i++) if (fi(i) == fi(i+n) && lo[i] == lo[i+n]) {ok = 0; break;}
    // set <int> st;
    // for (auto &u : C) for (auto [v, w] : adj[u]) if (lo[u] != lo[v]) st.emplace(w);
    // cout << st.size() << '\n';
    // for (auto &e : st) cout << e << ' ';
    // cout << '\n';
}