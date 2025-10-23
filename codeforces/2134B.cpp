/*
    author  : 
    created : 26/08/2025 21:38
    task    : 2134B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k; cin >> n >> k;
    ll a[n];
    if (k == 1) {
        for (auto &e : a) cin >> e, cout << e + (e % 2) << ' ';
        cout << '\n';
        return;
    }
    for (auto &e : a) {
        cin >> e;
        cout << e + k*((e % (k+1))) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}