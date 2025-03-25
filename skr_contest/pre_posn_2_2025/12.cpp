/*
    author  : PakinDioxide
    created : 18/03/2025 00:07
    task    : 12
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    ll a[n+2];
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[1], a[n+1] = a[n];
    ll pl[n+2], pr[n+2];
    pl[0] = pr[n+1] = 0;
    for (int i = 1; i <= n; i++) {
        pl[i] = pl[i-1] + (abs(a[i+1]-a[i]) >= abs(a[i]-a[i-1]) ? 0 : abs(a[i+1]-a[i]));
    }
    for (int i = n; i > 0; i--) {
        pr[i] = pr[i+1] + (abs(a[i+1]-a[i]) <= abs(a[i]-a[i-1]) ? 0 : abs(a[i-1]-a[i]));
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (r > l) cout << pl[r-1] - pl[l-1] << '\n';
        else cout << pr[r+1] - pr[l+1] << '\n';
    }
}