/*
    author  : 
    created : 26/08/2025 21:35
    task    : 2134A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if (n%2 == a%2 && n%2 == b%2) cout << "YES\n";
    else if (b > a && n%2 == b%2) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}