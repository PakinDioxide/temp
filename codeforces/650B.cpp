#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, a, b; ll T; cin >> n >> a >> b >> T;
    string s; cin >> s; ll mx = 0;
    for (int o = 0; o < 2; o++) {
        ll x[n]; memset(x, 0, sizeof(x));
        for (int i = 0; i < n; i++) x[i] += (s[i] == 'w') * b + 1;
        ll k = 0;
        for (int i = n-1; i > 0; i--) x[i-1] += x[i];
        for (int i = 0; i < n; i++) {
            k += x[i] - (i == n-1 ? 0 : x[i+1]) + a * (i > 0);
            if (k > T) break;
            ll t = T - k;
            int L = 1, R = (n-i-1), ans = 0;
            while (L <= R) {
                int M = L + (R-L)/2;
                // cout << M << ' ' << a * (M + i) + x[n-M] << '\n';
                if (t >= a * (M + i) + x[n-M]) ans = M, L = M+1;
                else R = M-1;
            }
            mx = max(mx, (ll) i+1+ans);
            // cout << i << ' ' << ans << '\n';
        }
        reverse(s.begin()+1, s.end());
    }
    cout << mx << '\n';
}