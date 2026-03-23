#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    for (int i = 0; i < n; i++) {
        int p = 0, q = 0;
        for (int j = i+1; j < n; j++) {
            if (a[i] > a[j]) p++;
            else if (a[i] < a[j]) q++;
        }
        cout << max(p, q) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
