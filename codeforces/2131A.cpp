/*
    author  : 
    created : 10/08/2025 21:35
    task    : 2131A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n; int a[n], b[n]; for (auto &e : a) cin >> e; for (auto &e : b ) cin >> e;
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += max(0, a[i] - b[i]); 
    cout << cnt+1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}