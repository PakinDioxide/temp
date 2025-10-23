/*
    author  : PakinDioxide
    created : 06/04/2025 01:22
    task    : C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n], b[n];
    for (auto &e : a) cin >> e, e--;
    for (auto &e : b) cin >> e, e--;
    ll k[n];
    for (int i = 0; i < n; i++) k[a[i]] = i;
    vector <ll> d;
    for (auto &E : b) {
        ll e = k[E];
        int idx = lower_bound(d.begin(), d.end(), e) - d.begin();
        if (idx == d.size()) d.emplace_back(e);
        else d[idx] = e;
    }
    cout << d.size() << '\n';
}