#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, m = 0;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n' << k << '\n';
        return;
    }
    else if (k == 1 || k == n) {
        cout << "-1\n";
        return;
    }
    int l = k-1, r = n - k;
    cout << 2*(min(l, r)) + 1 << '\n' << 1 << ' ';
    for (int i = 2; i <= min(l, r) - (k - min(l, r) + 1) % 2; i++) cout << i << ' ';
    cout << k << ' ';
    for (int i = 1; i < min(l, r) - (k - min(l, r) + 1) % 2; i++) cout << i + k << ' ';
    cout << n << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}