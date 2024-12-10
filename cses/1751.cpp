#include <bits/stdc++.h>

using namespace std;

int n, adj[200005], x[200005], vis[200005], dp[200005], id = 1;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> adj[i];
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        stack <int> st;
        int k = i;
        while (!vis[k]) {
            vis[k] = i;
            st.push(k);
            k = adj[k];
        }
        if (vis[k] == i) {
            vector <int> cyc;
            while (st.top() != k) cyc.push_back(st.top()), st.pop();
            cyc.push_back(st.top());
            st.pop();
            for (int j : cyc) dp[j] = cyc.size();
        }
        int r = k;
        while (!st.empty()) dp[st.top()] = dp[r] + 1, r = st.top(), st.pop();
    }
    for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
}