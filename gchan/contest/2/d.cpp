#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int d[n+1], x[n+1], dp[n+1], vis[n+1], ans = 0;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) cin >> x[i], vis[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        stack <int> st;
        int k = i;
        while (x[k] != k && !vis[k]) st.emplace(k), k = x[k];
        if (!vis[k]) dp[k] = d[k], vis[k] = 1;
        while (!st.empty()) vis[st.top()] = 1, dp[st.top()] = dp[k] + d[st.top()], k = st.top(), st.pop();
        ans = max(ans, dp[i]);
    }
    cout << ans;
}