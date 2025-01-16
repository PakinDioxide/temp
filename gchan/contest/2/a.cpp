#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

ll ncr(ll k) {
    if (k % 2 == 0) return ((k/2)*(k-1))%mod;
    else return (((k-1)/2)*k)%mod;
}

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    s += ' ';
    reverse(s.begin(), s.end());
    ll zr[n+1];
    zr[0] = 0;
    // cout << s << ' ' << ncr(5) << '\n';
    for (int i = 1; i <= n; i++) {zr[i] = zr[i-1]; if (s[i] == '0') zr[i]++;}
    ll ans = 0;
    for (int i = 1; i <= n; i++) if (s[i] == '6') ans += ncr(zr[i-1]), ans%=mod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}