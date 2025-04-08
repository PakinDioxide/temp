/*
    author  : PakinDioxide
    created : 27/03/2025 19:20
    task    : rap
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[27][27][26];

ll calc(int m, int r, int c) {
    return p[r][26][c]*(m/26LL) + p[r][m%26LL][c];
}

void solve() {
    ll m, k, c;
    char cc;
    cin >> m >> cc >> k;
    c = cc-'A';
    ll ans = 0;
    ans += 26LL*(k/calc(m, 26, c));
    k %= calc(m, 26, c);
    if (k == 0) ans -= 26, k = calc(m, 26, c);
    for (int i = 1; i <= 26; i++) {if (calc(m, i, c) >= k) break; ans++;}
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= 26; j++) {
            for (int k = 0; k < 26; k++) p[i][j][k] = p[i-1][j][k] + p[i][j-1][k] - p[i-1][j-1][k];
            p[i][j][((i-1)*(j-1)+(i-1)+(j-1))%26]++;
        }
    }
    while (q--) solve();
}