/*
    author  : PakinDioxide
    created : 24/04/2025 22:39
    task    : 2106E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n], idx[n-1];
    for (auto &e : a) cin >> e, e--;
    for (int i = 0; i < n; i++) idx[a[i]] = i;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k; l--, r--, k--;
        int id = idx[k];
        if (!(l <= id && id <= r)) {cout << -1 << ' '; continue;}
        int mnc = 0, mxc = 0, nc = k, xc = (n-1-k);
        while (l <= r) {
            if (l == r) break;
            int x = (l+r)/2;
            // cout << l << ' ' << r << ' ' << x << ' ' << id << '\n';
            if (x == id) break;
            if (x < id) mnc += (a[x] > k), nc -= (a[x] < k), l = x+1;
            else mxc += (a[x] < k), xc -= (a[x] > k), r = x-1;
        }
        mnc = max(mnc, mxc), mxc = max(mnc, mxc);
        // cout << "K " << mnc << ' ' << mxc << '\n';
        if (mnc > nc || mxc > xc || mnc + mxc > n-1) {cout << -1 << ' '; continue;}
        cout << mnc + mxc << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}