/*
    author  : PakinDioxide
    created : 28/04/2025 21:34
    task    : 2104A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll k = (a + b + c)/3;
    if ((a+b+c)%3 == 0 && a <= k && b <= k) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}