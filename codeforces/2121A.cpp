/*
    author  : 
    created : 17/06/2025 21:35
    task    : 2121A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, s; cin >> n >> s;
    int a[n]; for (auto &e : a) cin >> e;
    if (s >= a[0] && s <= a[n-1]) cout << min(s-a[0], a[n-1]-s) + a[n-1] - a[0] << '\n';
    else if (s >= a[n-1]) cout << s-a[0] << '\n';
    else cout << a[n-1] - s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}