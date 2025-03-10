#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, id = 0;
    cin >> n;
    int a[n+1], deg[n+1], vis[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i], deg[i] = vis[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        id++;
        stack <int> st;
        int k = i;
        while (!vis[k]) {
            st.push(k);
            vis[k] = id;
            k = a[k];
        }
        if (vis[k] == id) {
            while (st.top() != k) st.pop();
            st.pop();
        }
        while (!st.empty()) deg[st.top()] = deg[k] + 1, k = st.top(), st.pop();
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, deg[i]);
    cout << ans+2 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}