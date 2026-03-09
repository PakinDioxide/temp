#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5005;
const ll INF = 1e18;

int a[mxN], b[mxN];
vector <ll> dp[mxN][2];
vector <int> adj[mxN];

vector <ll> mg(vector <ll> x, vector <ll> y) {
    vector <ll> z((int) x.size() + y.size() - 1, INF);
    for (int i = 0; i < x.size(); i++) for (int j = 0; j < y.size(); j++) z[i+j] = min(z[i+j], x[i] + y[j]);
    return z;
}

void dfs(int u) {
    dp[u][0] = {0, a[u]};
    dp[u][1] = {INF, b[u]};
    for (auto v : adj[u]) {
        dfs(v);
        dp[u][0] = mg(dp[u][0], dp[v][0]);
        dp[u][1] = mg(dp[u][1], dp[v][1]);
    }
    for (int i = 0; i < dp[u][1].size(); i++) dp[u][1][i] = min(dp[u][1][i], dp[u][0][i]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        b[i] = a[i] - b[i];
        if (i > 1) { int x; cin >> x; adj[x].emplace_back(i); }
    }
    dfs(1);
    for (int i = n; i >= 0; i--) if (dp[1][1][i] <= k) cout << i << '\n', exit(0);
}

