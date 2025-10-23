/*
    author  : 
    created : 05/07/2025 21:50
    task    : 2119C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, l, r, k; cin >> n >> l >> r >> k;
    if (n % 2 == 1) { cout << l << '\n'; return; }
    ll p = 60, q = 60;
    while (!(l & (1LL << p))) p--;
    while (!(r & (1LL << q))) q--;
    if (p == q || (n == 2)) { cout << -1 << '\n'; return; }
    else cout << (k <= n-2 ? l : (1LL << (p+1))) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
3 = 0011
4 = 0100
5 = 0101
6 = 0110

3 4
*/