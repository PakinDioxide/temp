/*
    author  : 
    created : 02/07/2025 22:49
    task    : 2001C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    vector <pair <int, int>> adj;
    int vis[n+1]; memset(vis, 0, sizeof(vis));
    vector <int> tmp;
    map <pair <int, int>, int> dp, dd;
    auto ask = [&] (int u, int v) { if (dd[make_pair(u, v)]) return dd[make_pair(u, v)]; cout << "? " << u << ' ' << v << endl; int x; cin >> x; return x; };
    function <void(int, int)> dfs = [&] (int l, int r) {
        if (dp[make_pair(l, r)]) return;
        dp[make_pair(l, r)] = 1;
        int m = ask(l, r);
        if (l == m) { adj.emplace_back(l, r); vis[l] = vis[r] = 1; return; }
        dfs(l, m); dfs(m, r);
    };
    for (int i = 2; i <= n; i++) if (!vis[i]) dfs(1, i);
    sort(adj.begin(), adj.end());
    adj.resize(unique(adj.begin(), adj.end()) - adj.begin());
    cout << "! ";
    for (auto &e : adj) cout << e.first << ' ' << e.second << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
when we ask node u, v; let d be d(u, v) it will return u+d(u, v)/2 toward the lca
*/