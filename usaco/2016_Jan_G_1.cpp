/*
    author  : PakinDioxide
    created : 05/04/2025 00:59
    task    : 2016_Jan_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);
    int n;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e, e *= 2;
    sort(a, a+n);
    ll p[n], s[n];
    p[0] = s[n-1] = LLONG_MIN;
    for (int i = 1; i < n; i++) p[i] = (a[i] == a[i-1] ? p[i-1] : max(p[i-1]+2, a[i]-a[i-1]));
    for (int i = n-2; i >= 0; i--) s[i] = (a[i] == a[i+1] ? s[i+1] : max(s[i+1]+2, a[i+1]-a[i]));
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << p[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << s[i] << ' ';
    // cout << '\n';
    ll l = 0, r = 2e9+5, ans = 0;
    while (l <= r) {
        ll x = l + (r-l)/2;
        int idx1 = 0, idx2 = n-1;
        while (idx1+1 < n && p[idx1+1] <= x-2) idx1++;
        while (idx2-1 >= 0 && s[idx2-1] <= x-2) idx2--;
        ll dis = (a[idx2] - a[idx1])/2;
        if (dis <= x) ans = x, r = x-1;
        else l = x+1;
        // cout << (ok && dis <= x) << ' ' << dis << ' ' << idx1 << ' ' << idx2 << ' ' << x << '\n';
    }
    cout << fixed << setprecision(1) << ans/2.0 << '\n';
}