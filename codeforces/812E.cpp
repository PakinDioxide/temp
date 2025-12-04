#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int a[mxN], v = 0;
vector <int> adj[mxN];

void dfs(int u, int k) {
    k += a[u];
    for (auto v : adj[u]) dfs(v, k);
    if (adj[u].empty()) v ^= k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2, x; i <= n; i++) cin >> x, adj[x].emplace_back(i);
    int c = 0;
    for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++) {
        swap(a[i], a[j]);
        v = 0; dfs(1, 0);
        if (v == 0) c++, cout << i << ' ' << j << '\n';
        swap(a[i], a[j]);
    }
    cout << c << '\n';
}

/*
lets consider a more simple version

no changes to the tree are made

check if who would win

            7
        2   2   5
               4 3
               1 1
*/