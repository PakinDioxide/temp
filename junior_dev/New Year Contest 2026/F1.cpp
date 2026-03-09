#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    if (n % 2 == 1) {
        cout << "YES\n";
        for (int i = 1; i <= n/2; i++) cout << i << ' ' << n-i+1 << '\n';
        for (int i = n/2; i >= 1; i--) cout << i << ' ' << i+1 << '\n';
    } else if (n % 4 == 0) {
        cout << "YES\n";
        for (int i = n; i > 0; i -= 4) {
            cout << i-3 << ' ' << i-1 << '\n';
            cout << i-3 << ' ' << i-2 << '\n';
            cout << i-3 << ' ' << i-2 << '\n';
        }
        int c = n/4;
        for (int i = 1; i <= c/2; i++) cout << i << ' ' << c-i+1 << '\n';
        for (int i = c/2 - !(c % 2); i >= 1; i--) cout << i << ' ' << i+1 << '\n';
    } else if (n == 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < n-4; i++) cout << 1 << ' ' << 3 << '\n';
        cout << 1 << ' ' << 3 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

