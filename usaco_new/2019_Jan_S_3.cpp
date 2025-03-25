/*
    author  : PakinDioxide
    created : 18/03/2025 17:06
    task    : 2019_Jan_S_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    int n, idx = 0;
    ll x, y;
    cin >> n;
    vector <ll> v;
    tuple <ll, ll, int> a[n];
    for (auto &[l, r, id] : a) cin >> x >> y, l = x-y, r = x+y, id = idx++, r = -r;
    sort(a, a+n);
    set <ll> k;
    int cnt = 0;
    for (auto &[l, r, id] : a) {
        r=-r;
        auto it = k.lower_bound(r);
        if (it == k.end()) cnt++;
        k.insert(r);
    }
    cout << cnt << '\n';
}