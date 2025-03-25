/*
    author  : PakinDioxide
    created : 25/03/2025 19:31
    task    : sequence
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, a1, d, q;
    cin >> n >> a1 >> d >> q;
    ll a[n+1], p[n+1];
    p[0] = 0;
    a[0] = LLONG_MIN;
    a[1] = p[1] = a1;
    for (int i = 2; i <= n; i++) a[i] = a[i-1] + d, p[i] = a[i] + p[i-1];
    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (d == 0) {cout << (l <= a1 && a1 <= r ? n*a1 : 0) << '\n'; continue;}
        ll idx1 = lower_bound(a, a+n, l) - a, idx2 = upper_bound(a, a+n+1, r) - a - 1;
        cout << p[idx2] - p[idx1-1] << '\n';
    }
}