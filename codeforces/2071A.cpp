#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n;
    cin >> n;
    if (n%3 == 1) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}