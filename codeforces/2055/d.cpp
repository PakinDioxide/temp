#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k, l;
    cin >> n >> k >> l;
    double a[n], td[n];
    for (int i = 0; i < n; i++) cin >> a[i], td[i] = 0;
    double t = 0, x = 0;
    int idx = 0;
    while (x < l) {
        // cout << "HA " << x << '\n';
        // for (int i = 0; i < n; i++) cout << a[i] << ' ';
        // cout << '\n';
        while (idx < n-1 && a[idx+1] < x) idx++;
        if (x - a[idx] < k) {x += k; continue;}
        double nxt = max(0.0, x-k+2);
        // cout << "NXT " << nxt << '\n';
        if (idx < n-1 && max(0.0, nxt - a[idx] - t + td[idx]) > max(0.0, a[idx+1] - nxt - t + td[idx+1])) x = nxt+k, t += max(0.0, a[idx+1] - nxt - t + td[idx+1]), a[idx+1] = nxt, td[idx+1] = t;
        else x = nxt+k, t += max(0.0, nxt - a[idx] - t + td[idx]), a[idx] = nxt, td[idx] = t;
    }
    cout << 2*t << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
