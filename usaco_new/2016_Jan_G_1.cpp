/*
    author  : PakinDioxide
    created : 14/03/2025 14:28
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
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    ll l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        ll rd = l+(r-l)/2;
        ll x = 0, y = 1e9, idx = -1;
        while (x < y) {
            
        }
    }
}