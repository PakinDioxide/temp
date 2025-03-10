#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[200005];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= max(n, k); i++) a[i] = 0;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[x] -= y;
    }
    sort(a, a + k + 1);
    ll sum = 0;
    for (int i = 0; i < n; i++) sum -= a[i];
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}