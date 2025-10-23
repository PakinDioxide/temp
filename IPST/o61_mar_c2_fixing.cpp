/*
    author  : PakinDioxide
    created : 05/05/2025 20:58
    task    : o61_mar_c2_fixing
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[m], s = 0;
    vector <ll> v;
    for (auto &e : a) cin >> e;
    for (int i = 1; i < m; i++) v.emplace_back(a[i] - a[i-1] - 1);
    sort(v.begin(), v.end());
    for (int i = 0; i < (int) v.size() - k + 1; i++) s += v[i];
    cout << s << '\n';
}