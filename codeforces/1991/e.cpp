#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector <int> adj[n+1];
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);   
    }
    
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}