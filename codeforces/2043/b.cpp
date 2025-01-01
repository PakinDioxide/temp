#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    cout << 1 << ' ';
    if (n >= 3 || d % 3 == 0) cout << 3 << ' ';
    if (d%5 == 0) cout << 5 << ' ';
    if (n >= 3 || d == 7) cout << 7 << ' '; 
    if (n >= 6 || d == 9 || (n >= 3 && d%3 == 0)) cout << 9 << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    // int d = 1;
    // while (d % 5 && d > 0) d=10*d+1;
    // cout << d;
}