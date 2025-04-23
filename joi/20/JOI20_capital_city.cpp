/*
    author  : PakinDioxide
    created : 17/04/2025 20:52
    task    : JOI20_capital_city
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, k;
vector <int> adj[mxN];

void dfs(int u, int p) {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

}

/*

*/