#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 0; i < n-2; i++) cout << 3;
        cout << 66;
        cout << '\n';
    } else {
        if (n <= 3) cout << "-1\n";
        else {
            for (int i = 0; i < n-4; i++) cout << 3;
            cout << "6366\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}