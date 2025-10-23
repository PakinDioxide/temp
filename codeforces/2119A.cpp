/*
    author  : 
    created : 05/07/2025 21:35
    task    : 2119A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int a, b; ll x, y; cin >> a >> b >> x >> y;
    if (a > b+1 || (a == b+1 && a % 2 == 0)) cout << -1 << '\n';
    else if (a == b+1) cout << y << '\n';
    else {
        ll cnt = 0;
        while (a != b) {
            if (a % 2 == 0) cnt += min(x, y);
            else cnt += x;
            a++;
        }
        cout << cnt << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}