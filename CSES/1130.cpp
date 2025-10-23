#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> adj[200005];
int dp[200005][2];

void dfs(int u, int p) {	
	dp[u][0] = dp[u][1] = 0;
	int mn = INT_MAX, idx = -1, cnt = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		cnt = 1;
		dfs(v, u);
		dp[u][0] += dp[v][1];
		if (dp[v][1] - dp[v][0] < mn) mn = dp[v][1] - dp[v][0], idx = v;
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		if (v == idx) dp[u][1] += dp[v][0];
		else dp[u][1] += dp[v][1];
	}
	if (cnt) dp[u][1]++;
}

int main() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	dfs(1, 0);
	cout << max(dp[1][0], dp[1][1]);
}
