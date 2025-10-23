/*
    author  : PakinDioxide
    created : 25/03/2025 22:56
    task    : 1643
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n+1], p[n+1];
    p[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i-1] + a[i];
    ll mn = 0, mx = LLONG_MIN;
    for (int i = 1; i <= n; i++) mx = max(mx, p[i] - mn), mn = min(mn, p[i]);
    cout << mx << '\n';
}