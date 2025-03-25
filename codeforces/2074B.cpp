/*
    author  : PakinDioxide
    created : 11/03/2025 21:36
    task    : 2074B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    for (int i = 0; i < n-1; i++) {
        a[i+1] = a[i] + a[i+1] - 1;
    }
    cout << a[n-1] << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}