/*
    author  : 
    created : 30/06/2025 22:20
    task    : 1709B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    ll l[n+1], r[n+2], a[n+2]; l[0] = r[n+1] = a[0] = a[n+1] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) l[i] = l[i-1] + max(0ll, a[i-1] - a[i]);
    for (int i = n; i >= 1; i--) r[i] = r[i+1] + max(0ll, a[i+1] - a[i]);
    while (q--) {
        int x, y; cin >> x >> y;
        if (x <= y) cout << l[y] - l[x] << '\n';
        else cout << r[y] - r[x] << '\n';
    }
}