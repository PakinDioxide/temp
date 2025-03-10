#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll b[2*n], k = 0;
    map <ll, int> vis;
    for (auto &e : b) cin >> e, vis[e] = 1;
    sort(b, b+2*n);
    for (int i = 2*n-1; i >= n; i--) k += b[i];
    for (int i = n-1; i >= 0; i--) k -= b[i];
    ll a[2*n];
    int l = 0, r = 2*n-1;
    for (int i = 0; i < 2*n; i++) {
        if (i % 2 == 0) a[i] = b[r--];
        else a[i] = b[l++];
    }
    if (vis[k]) {
        k = b[2*n-1];
        a[0] = 0;
        for (int i = 2*n-1; i >= n-1; i--) a[0] += b[i];
        for (int i = n-2; i >= 0; i--) a[0] -= b[i];
        int l = 0, r = 2*n-2;
        for (int i = 1; i < 2*n; i++) {
            if (i % 2 == 1) a[i] = b[r--];
            else a[i] = b[l++];
        }
    }
    cout << k << ' ';
    for (auto e : a) cout << e << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}