#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e3+5;

int n, k;
int A[2][mxN], ID[mxN], par[mxN], it = 0, dep[mxN];
vector <int> adj[mxN], q;
vector <pair <int, int>> S[2], Q;

void dfs(int u, int p) {
    dep[u] = dep[p]+1;
    for (auto v : adj[u]) if (v != p) dfs(v, u);
    Q.emplace_back(dep[u], u);
}

void dfs_par(int u, int p) {
    par[u] = p;
    for (auto v : adj[u]) if (v != p) dfs_par(v, u);
}

void dfs_push(int u, int p, int id) {
    if (ID[u] < it) return;
    for (auto v : adj[u]) if (v != p) dfs_push(v, u, id);
    if (A[id][u] == 1) {
        for (auto v : adj[u]) if (v != p && ID[v] >= it && !A[id][v]) {
            int mx = 0;
            for (auto &e : adj[v]) if (e != u) mx = max(mx, A[id][e]);
            if (mx == 0) {
                A[id][v] = 1;
                A[id][u] = 0;
                if (S[id].size() && S[id].back() == make_pair(v, u)) S[id].pop_back();
                else S[id].emplace_back(u, v);
                break;
            }
        }
    }
}

void dfs_pull(int u, int p, int id) {
    if (ID[u] < it || A[id][u]) return;
    int cnt = 0, idx = -1;
    for (auto v : adj[u]) cnt += A[id][v], idx = (A[id][v] ? v : idx);
    if (cnt == 1 && ID[idx] >= it) {
        A[id][u] = 1;
        A[id][idx] = 0;
        if (S[id].size() && S[id].back() == make_pair(u, idx)) S[id].pop_back();
        else S[id].emplace_back(idx, u);
        return;
    } else if (cnt >= 1) return;

    for (auto v : adj[u]) if (v != p && ID[v] >= it) {
        dfs_pull(v, u, id);
        if (A[id][v] == 1) {
            A[id][u] = 1;
            A[id][v] = 0;
            if (S[id].size() && S[id].back() == make_pair(u, v)) S[id].pop_back();
            else S[id].emplace_back(v, u);
            return;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) A[0][i] = A[1][i] = 0, adj[i].clear();
    q.clear(), Q.clear(); it = 0;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].emplace_back(v), adj[v].emplace_back(u);
    cin >> k;
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        A[0][x] = 1;
    }
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        A[1][x] = 1;
    }
    vector <pair <int, int>>().swap(S[0]);
    vector <pair <int, int>>().swap(S[1]);

    q.emplace_back(0);
    dfs(1, 0);
    sort(Q.begin(), Q.end());
    while (Q.size()) q.emplace_back(Q.back().second), ID[Q.back().second] = ++it, Q.pop_back();
    it = 1;
    for (it = 1; it <= n; it++) {
        int e = q[it];
        dfs_par(e, e);
        dfs_push(e, e, 0);
        dfs_pull(e, e, 0);
        // cout << "# " << it << ' ' << q[it] << '\n'; for (int i = 1; i <= n; i++) cout << A[0][i] << ' '; cout << '\n';
    }
    // return;
    for (it = 1; it <= n; it++) {
        int e = q[it];
        dfs_par(e, e);
        dfs_push(e, e, 1);
        dfs_pull(e, e, 1);
        // cout << "# " << it << ' ' << q[it] << '\n'; for (int i = 1; i <= n; i++) cout << A[1][i] << ' '; cout << '\n';
    }
    // for (int i = 1; i <= n; i++) cout << A[0][i] << ' '; cout << '\n';
    // for (int i = 1; i <= n; i++) cout << A[1][i] << ' '; cout << '\n';
    for (int i = 1; i <= n; i++) if (A[0][i] != A[1][i]) { cout << "NO\n"; return; }
    cout << "YES\n" << (int) S[0].size() + S[1].size() << '\n';
    reverse(S[1].begin(), S[1].end());
    for (auto &[u, v] : S[0]) cout << u << ' ' << v << '\n';
    for (auto &[v, u] : S[1]) cout << u << ' ' << v << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

