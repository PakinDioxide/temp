#include <bits/stdc++.h>

using namespace std;

int l = 0, x = 1, cnt = 0;
map <int, pair <int, int>> dp;

void solve() {
    int n, ok = 0;
    cin >> n;
    if (n <= cnt) {cout << dp[n].first << ' ' << dp[n].second << '\n'; return;}
    while (cnt < n) {
        // cout << "HI";
        while (x <= l) {
            if (__gcd((l-x+1), x) != 1) {x++; continue;}
            cnt++;
            dp[cnt] = {x, l-x+1};
            if (cnt == n) {
                cout << x << ' ' << l-x+1 << '\n';
                x++;
                break;
            }
            x++;
        }
        if (x == l+1) {
            x = 1;
            l++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}