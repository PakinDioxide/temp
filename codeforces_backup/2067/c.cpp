#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k = 0, kk = 1, kkk = 1, ans = 9, cc = 0, ccc = 0;
    cin >> n;
    while (1) {
        ll x = n%10;
        n /= 10;
        ll xx = k+kk*x;
        for (ll i = 0; i <= 9; i++) {
            if ((xx/kk) % 10 == 7) {ans = min(ans, i); break;}
            // cout << "KK " << xx << ' ' << kk << '\n';
            xx += 9*kkk;
        }
        ll need = (7-x+20)%10;
        // cout << "NEED" << need << ' ' << need+(need > k) << '\n';
        if (cc > 0) ans = min(ans, need+(need > k));
        k += kk*x;
        kk *= 10;
        kkk += kk;
        cc++;
        if (ccc == 1) break;
        if (n == 0) ccc = 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

// 800001
