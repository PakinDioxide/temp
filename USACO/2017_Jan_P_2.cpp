#include <bits/stdc++.h>
#define ll long long
#define db double

using namespace std;

const int mxN = 1e5+5;

ll a[mxN], n, k;

ll calc(db ld) {
    // a/(c)(c+1) >= ld
    // a >= ld(c)(c+1)
    // 0 >= ld(c)(c+1) - a
    // 0 >= ldc^2 + ldc - a
    // c <= (-ld + sqrt(ld^2 + 4lda))/2ld
    // c <= (-1 + sqrt(1 + 4a/ld))/2
    ll tot = 0;
    for (int i = 1; i <= n; i++) tot += (-1 + sqrt(1 + 4*a[i]/ld))/2;
    return tot;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("tallbarn.in", "r", stdin);
    freopen("tallbarn.out", "w", stdout);
    cin >> n >> k;
    k -= n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    db l = 0, r = 1e18;
    for (int i = 0; i < 200; i++) {
        db m = l + (r-l)/2;
        if (calc(m) >= k) l = m;
        else r = m;
    }
    db ans = 0;
    ll tot = 0;
    for (int i  = 1; i <= n; i++) {
        ll x = (-1 + sqrt(1 + 4*a[i]/l))/2;
        ans += (db) a[i]/(x+1);
        tot += x;
    }
    cout << (ll) round(ans - (k-tot)*l) << '\n';
}
