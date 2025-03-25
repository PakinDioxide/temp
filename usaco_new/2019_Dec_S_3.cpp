/*
    author  : PakinDioxide
    created : 23/03/2025 16:48
    task    : 2019_Dec_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <int> adj[100005];
int dep[100005], par[100005];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1;
        par[v] = u;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    string a;
    cin >> a;
    a = ' ' + a;
    int par[n+1];
    iota(par, par+n+1, 0);
    function <int(int)> fi = [&] (int x) {
        if (x != par[x]) return par[x] = fi(par[x]);
        return x;
    };
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (a[u] == a[v]) par[fi(u)] = fi(v);
    }
    dfs(1, 0);
    while (q--) {
        int x, y;
        char k;
        cin >> x >> y >> k;
        if (fi(x) != fi(y) || a[x] == k) cout << 1;
        else cout << 0;
    }
    cout << '\n';
}