#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; ll x;
    cin >> n >> x;
    ll a[n], k = 0;
    if (n == 1) {cout << x << '\n'; return;}
    a[0] = 0;
    for (int i = 1; i < n; i++) {
        if ((x | i) == x) a[i] = i, k |= i;
        else {
            for (int j = i; j < n; j++) a[j] = x;
            k = x;
            break;
        }
    }
    if (k != x) a[n-1] = x;
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}