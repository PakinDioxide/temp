/*
    author  : PakinDioxide
    created : 13/05/2025 20:03
    task    : 1029
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n], ans[n];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    int l = 0, r = n-1, x = 0;
    vector <int> vis(n);
    for (int i = 0; i < n && l <= r; i++) {
        if (vis[a[i]]) continue;
        while (vis[b[x]] && x < n) x++;
        if (x == n) break;
        if (a[i] != b[x]) ans[l++] = a[i], ans[r--] = b[x], vis[a[i]] = vis[b[x]] = 1;
        else ans[l++] = a[i], vis[a[i]] = 1;
        x++;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}