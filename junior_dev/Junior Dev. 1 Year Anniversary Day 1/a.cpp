/*
    author  : PakinDioxide
    created : 22/09/2025 17:57
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a[100], p[100];
    memset(p, 0, sizeof(p));
    a[0] = 1;
    for (int i = 1; i < 100; i++) {
        a[i] = 0;
        if (i >= 6) a[i] = max(a[i], a[i-6]);
        if (i >= 9) a[i] = max(a[i], a[i-9]);
        if (i >= 20) a[i] = max(a[i], a[i-20]);
        if (!a[i]) p[i]++;
        p[i] += p[i-1];
    }
    ll ans = 0;
    int q; cin >> q;
    while (q--) {
        ll l, r; cin >> l >> r;
        ans += (r-l+1) - p[min(r, (ll) 99)] + p[min(l-1, (ll) 99)];
    }
    cout << ans << '\n';
}