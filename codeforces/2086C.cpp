/*
    author  : PakinDioxide
    created : 03/04/2025 21:52
    task    : 2086C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n;
    cin >> n;
    int p[n+1], d[n+1];
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    int cyc[n+1], vis[n+1], cycidx[n+1], visidx[n+1], idx = 0;
    memset(cyc, 0, sizeof(cyc));
    memset(vis, 0, sizeof(vis));
    memset(visidx, 0, sizeof(visidx));
    memset(cycidx, 0, sizeof(cycidx));
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int x = p[i], cnt = 0;
        stack <int> st;
        while (!vis[x]) st.emplace(x), vis[x] = 1, x = p[x], cnt++;
        while (!st.empty()) cyc[st.top()] = cnt, cycidx[st.top()] = idx, st.pop();
        idx++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int e = d[i];
        if (visidx[cycidx[e]]) {cout << ans << ' '; continue;}
        ans += cyc[e];
        visidx[cycidx[e]] = 1;
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}