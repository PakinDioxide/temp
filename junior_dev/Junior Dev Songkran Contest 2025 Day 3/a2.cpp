/*
    author  : PakinDioxide
    created : 15/04/2025 18:01
    task    : a1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int n, q;
ll a[mxN];
vector <bool> dp[40], dpl[40], dpr[40];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < 40; i++) dp[i].resize(n+5), dpl[i].resize(n+5), dpr[i].resize(n+5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < 40; i++) for (int j = 1; j <= n; j++) dp[i][j] = dp[i][j-1] ^ ((a[j] & (1LL << i)) != 0);
    for (int i = 0; i < 40; i++) for (int j = 1; j <= n; j++) dpl[i][j] = dpl[i][j-1] ^ ((((a[j] & (1LL << i)) != 0)*j)%2);
    for (int i = 0; i < 40; i++) for (int j = n; j >= 1; j--) dpr[i][j] = dpr[i][j+1] ^ ((((a[j] & (1LL << i)) != 0)*(n-j+1))%2);
    // cout << "ONE\n";
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 1; j <= n; j++) cout << dpl[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << "R\n";
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 1; j <= n; j++) cout << dpr[i][j] << ' ';
    //     cout << '\n';
    // }
    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll ans = 0, idx = l + (r-l)/2;
        ll mx = min(k, r-l+1 - k + 1), L = l + mx-1, R = r - mx+1;
        if (L == R) R++;
        // cout << mx << ' ' << L << ' ' << R << '\n';
        for (int i = 0; i < 40; i++) {
            ll x = 0;
            if (R-L-1 > 0) x += ((dp[i][R-1] ^ dp[i][L])%2)*(mx%2);
            x += (dpl[i][L] ^ dpl[i][l-1] ^ (dp[i][L] ^ dp[i][l-1])*(l-1))%2;
            x += (dpr[i][R] ^ dpr[i][r+1] ^ (dp[i][r] ^ dp[i][R-1])*(n-r))%2;
            // x = (abs(x)) % 2;
            x %= 2;
            ans += (1LL << i)*x;
        }
        cout << ans << '\n';
    }
}

/*
each bit of each value at index = idx, k = k will appered 
    min(idx - max(l, idx-k+1) + 1, min(r, idx+k-1) - idx + 1)

the maximum time each element will appered is k times

the multiplier is an increaseing step

1, 2, .., k, .. k, .. 2, 1

00001
00010
00011
00100
00001
00010
00100
01111
00011
*/