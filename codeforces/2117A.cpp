/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    int a[n]; for (auto &e : a) cin >> e;
    int l = n+1, r = 0;
    for (int i = 0; i < n; i++) if (a[i]) l = min(i, l), r = max(i, r);
    if (r-l+1 <= x) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
