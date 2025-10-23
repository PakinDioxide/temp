#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    int a[n+2];
    vector <int> v;
    a[0] = a[n+1] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) v.push_back(a[i-1] + a[i] + a[i+1]);
    sort(v.begin(), v.end());
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ll = lower_bound(v.begin(), v.end(), l) - v.begin();
        int rr = upper_bound(v.begin(), v.end(), r) - v.begin();
        cout << rr - ll << '\n';
    }
}