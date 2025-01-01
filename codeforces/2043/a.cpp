#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, ans = 1;
    cin >> n;
    while (n > 3) n/=4, ans *= 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}