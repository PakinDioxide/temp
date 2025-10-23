/*
    author  : PakinDioxide
    created : 12/03/2025 18:11
    task    : 1074
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    int k = a[n/2];
    ll ans = 0;
    for (auto &e : a) ans += abs(k-e);   
    cout << ans << '\n';
}