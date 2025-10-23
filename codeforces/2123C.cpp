/*
    author  : 
    created : 01/07/2025 21:47
    task    : 2123C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n; int a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l[n+2], r[n+2];
    l[0] = INT_MAX, r[n+1] = -1;
    for (int i = 1; i <= n; i++) l[i] = min(l[i-1], a[i]);
    for (int i = n; i >= 1; i--) r[i] = max(r[i+1], a[i]);
    unordered_map <int, int> vis;
    for (int i = 1; i <= n; i++) vis[min(l[i-1], r[i])] = vis[max(l[i], r[i+1])] = 1;
    for (int i = 1; i <= n; i++) cout << vis[a[i]]; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}