#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, h, d, s, p;
    cin >> n >> h >> d >> s >> p;
    double l = 0, r = INT_MAX, ans = -1, time = (double) d/s;
    while (l <= r) {
        double mid = l + (r-l)/2;
        double heal = mid - time;
        if (heal < 0 || (double) heal * h + n < mid * p) {
            l = mid + 0.000001;
        } else {
            ans = mid;
            r = mid - 0.000001;
        }
    }
    if (n >= time * p) {
        if (ans != -1) ans = min(ans, time);
        else ans = time;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}