/*
    author  : PakinDioxide
    created : 16/03/2025 01:41
    task    : d
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int vis[n+1], a[n+1], pos[n+1];
    vector <int> k;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!vis[a[i]]) k.push_back(a[i]);
        vis[a[i]] = 1;
    }
    for (int i = 0; i < k.size(); i++) pos[k[i]] = i;
    int ans = n, idx = k.size()-1, cnt = 0;
    for (int i = n; i > 0; i--) {
        if (a[i] == k[idx]) cnt++, idx--;
        else if (a[i] == k.back()) cnt = 1, idx = k.size()-2;
        else if (idx != k.size()-1 && a[i] == k[idx+1]) cnt++;
        else if (pos[a[i]] > idx) cnt = 0, idx = k.size()-1;
        else if (idx < k.size()-1) cnt++;
        if (idx == -1) {
            ans = min(ans, cnt);
            cnt = 0, idx = k.size()-1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}