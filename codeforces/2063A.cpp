#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll x, y;
    cin >> x >> y;
    cout << y-x + (x==y && x == 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}