/*
    author  : PakinDioxide
    created : 25/03/2025 17:07
    task    : 1632
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, cnt = 0;
    cin >> n >> k;
    pair <ll, ll> a[n];
    for (auto &[y, x] : a) cin >> x >> y;
    sort(a, a+n);
    multiset <ll> et;
    for (int i = 0; i < k; i++) et.insert(0);
    for (auto &[y, x] : a) {
        auto it = et.upper_bound(x);
        if (it == et.begin()) continue;
        it = prev(it);
        et.erase(it);
        et.insert(y);
        cnt++;
    }
    cout << cnt << '\n';
}