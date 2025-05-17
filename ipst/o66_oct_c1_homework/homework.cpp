#include <bits/stdc++.h>
#include "homework.h"
#define ll long long

using namespace std;

int homework(int n, vector<vector<int>> hw, vector<vector<int>> adj) {
    vector <ll> deg(n), dp(n, 0), l(n), r(n), m(n), adjt[n];
    for (int i = 0; i < n; i++) for (auto &e : adj[i]) adjt[e].emplace_back(i);
    priority_queue <pair <ll, ll>> q;
    for (int i = 0; i < n; i++) { l[i] = hw[i][0], r[i] = hw[i][1], m[i] = hw[i][2], deg[i] = hw[i][3]; if (!deg[i]) { int k = ceil((double)l[i]/m[i])*m[i]; if (k <= r[i]) q.emplace(-(dp[i] = k), i); } }
    ll cnt = 0;
    while (!q.empty()) {
        auto [w, u] = q.top(); w=-w; q.pop();
        cnt++;
        for (auto v : adjt[u]) {
            if (deg[v] == 0) continue;
            dp[v] = max(dp[v], dp[u]+1);
            if (--deg[v] == 0) {
                dp[v] = max(dp[v], l[v]);
                dp[v] = ceil((double)dp[v]/m[v])*m[v];
                if (dp[v] <= r[v]) q.emplace(-dp[v], v);
            }
        }
    }
    return cnt;
}