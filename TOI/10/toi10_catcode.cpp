/*
    author  : PakinDioxide
    created : 09/04/2025 01:50
    task    : toi10_catcode
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll M = 1e9+9;
const ll A = 19973;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int m, n;
    cin >> m >> n;
    string x[m];
    for (auto &e : x) cin >> e;
    ll h[m][n], p[n+1];
    for (int i = 0; i < m; i++) {
        h[i][0] = x[i][0];
        for (int j = 1; j < n; j++) h[i][j] = ((h[i][j-1]*A)%M + x[i][j])%M;
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++) p[i] = (p[i-1]*A)%M;
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        string s;
        cin >> s;
        ll hx[k];
        hx[0] = s[0];
        for (int i = 1; i < k; i++) hx[i] = ((hx[i-1]*A)%M + s[i])%M;
        unordered_map <ll, ll> mp;
        for (int i = 0; i+n-1 < k; i++) mp[(hx[i+n-1] - ((i == 0 ? 0LL : hx[i-1])*p[n])%M + M)%M] = 1;
        int cnt = 0;
        for (int i = 0; i < m; i++) if (mp[h[i][n-1]]) cout << i+1 << ' ', cnt++;
        if (cnt == 0) cout << "OK";
        cout << '\n';
    }
}