/*
    author  : 
    created : 19/07/2025 21:54
    task    : 2122B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n], b[n], c[n], d[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    ll cnt = 0;
    for (int i = 0; i < n; i++) cnt += (b[i] > d[i])*(min(a[i], c[i]) + max(0LL, b[i] - d[i])) + max(0LL, a[i] - c[i]);
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}