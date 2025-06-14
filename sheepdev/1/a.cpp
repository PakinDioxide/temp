/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

const int mxN = 1e6;
int c[mxN], ans[mxN], n;
vector <int> adj[mxN];
unordered_map <int, stack <int>> s;

void dfs(int u) {
    if (s[c[u]].empty()) ans[u] = 0;
    else ans[u] = s[c[u]].top();
    for (auto &v : adj[u]) {
        s[c[u]].emplace(v);
        dfs(v);
        s[c[u]].pop();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1, p; i < n; i++) cin >> p, adj[p].emplace_back(i);
    for (int i = 0; i < n; i++) cin >> c[i];
    dfs(0);
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}


