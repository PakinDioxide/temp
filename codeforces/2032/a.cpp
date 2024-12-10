#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a = 0, b = 0, x;
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        cin >> x;
        if (x) b++;
        else a++;
    }
    cout << a % 2 << ' ' << min(a, b) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}