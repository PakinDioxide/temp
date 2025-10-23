#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    int l = 1, r = min(a, b), ans = 0;
    while (l <= r) {
        int x = l + (r-l)/2;
        if (n <= a/x + b/x) l = x+1, ans = x;
        else r = x-1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // int t; cin >> t;
    int t = 1;
    while (t--) solve();
}