/*
    author  : PakinDioxide
    created : 14/03/2025 21:35
    task    : 983
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll a[n], sum = 0;
    for (auto &e : a) cin >> e, sum += e;
    while (q--) {
        int k;
        cin >> k;
        ll l = 0, r = sum, ans = 0;
        while (l <= r) {
            ll p = l + (r-l)/2, sum = 0, cnt = 0;
            for (auto e : a) {
                if (e + sum >= p) cnt++, sum = 0;
                else sum += e;
            }
            if (sum) cnt++;
            if (cnt <= k) r = p-1, ans = p;
            else l = p+1;
        }
        cout << ans << '\n';
    }   
}