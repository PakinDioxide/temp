/*
    author  : PakinDioxide
    created : 17/03/2025 19:03
    task    : 02
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    ll l = 0, r = LLONG_MAX, ans = 0;
    while (l <= r) {
        ll mid = l+(r-l)/2;
        ll cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += mid/a[i];
            if (cnt >= k) break;
        }
        if (cnt >= k) r = mid-1, ans = mid;
        else l = mid+1;
    }   
    cout << ans << '\n';
}