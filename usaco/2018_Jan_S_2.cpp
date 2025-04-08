/*
    author  : PakinDioxide
    created : 05/04/2025 17:29
    task    : 2018_Jan_S_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("rental.in", "r", stdin);
    // freopen("rental.out", "w", stdout);
    ll n, m, r;
    cin >> n >> m >> r;
    ll a[n], rent[r];
    pair <ll, ll> milk[m];
    for (auto &e : a) cin >> e;
    for (auto &[x, y] : milk) cin >> x >> y;
    for (auto &e : rent) cin >> e;
    sort(a, a+n);
    sort(milk, milk+m);
    sort(rent, rent+r);
    reverse(a, a+n);
    reverse(milk, milk+m);
    reverse(rent, rent+r);
    ll ans = 0, idxl = 0, idxr = n-1;
    while (idxl <= idxr) {
        ll idx = idxl;
    }
}