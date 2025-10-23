/*
    author  : 
    created : 01/07/2025 21:37
    task    : 2123B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, j, k; cin >> n >> j >> k;
    int a[n]; for (auto &e : a) cin >> e;
    j = a[j-1];
    sort(a, a+n);
    if (k >= 2 || j == a[n-1]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}