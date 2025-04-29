/*
    author  : PakinDioxide
    created : 28/04/2025 21:39
    task    : 2104B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n+2], P[n+2];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll p[n+2]; p[0] = P[n+1] = 0;
    for (int i = 1; i <= n; i++) p[i] = max(a[i], p[i-1]);
    for (int i = n; i >= 1; i--) P[i] = P[i+1] + a[i];
    for (int i = 1; i <= n; i++) cout << max(P[n-i+1], P[n-i+2] + p[n-i]) << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}