#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, cnt = 2, k = 4;
    cin >> n;
    if (n == 1) {cout << 1 << '\n'; return;}
    while (2*(k+1) <= n) k=(k+1)*2, cnt++;
    if (n > k) cnt++;
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}