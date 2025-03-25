/*
    author  : PakinDioxide
    created : 17/03/2025 19:19
    task    : 03
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k;
    cin >> n >> k;
    ll a[n], mn = 0;
    for (auto &e : a) cin >> e, mn = max(mn, e);
    ll l = mn, r = LLONG_MAX, ans = 0;
    while (l <= r) {
        ll w = l+(r-l)/2, sum = 0, cnt = 1;
        for (auto e : a) {
            if (sum + e > w) sum = e, cnt++;
            else sum += e;
        }
        if (cnt <= k) r = w-1, ans = w;
        else l = w+1;
    }
    cout << ans << '\n';
}