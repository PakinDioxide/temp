#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a = 0, b = 0, x, y;
    cin >> n;
    while (n--) cin >> a >> b, x = max(x, a), y = max(y, b);
    cout << (x+y)*2 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}