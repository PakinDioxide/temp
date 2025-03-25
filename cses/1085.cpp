/*
    author  : PakinDioxide
    created : 15/03/2025 00:10
    task    : 1085
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll a[n], ss = 0, mx = 0;
    for (auto &e : a) cin >> e, ss += e, mx = max(mx, e);
    ll l = mx, r = ss, ans;
    while (l <= r) {
        ll mid = l + (r-l)/2, sum = 0, cnt = 1;
        for (auto &e : a) {
            if (e + sum > mid) sum = e, cnt++;
            else sum += e;
        }
        if (cnt <= k) r = mid-1, ans = mid;
        else l = mid+1;
    }
    cout << ans << '\n';
}