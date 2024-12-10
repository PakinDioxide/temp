#include <bits/stdc++.h>
#define ll long long

using namespace std;


void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    int b[m+5][n+5];
    for (int i = 0; i <= m; i++) b[i][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> b[j][i], b[j][i] |= b[j][i-1];
    while (q--) {
        int k;
        cin >> k;
        int l = 1, r = n;
        while (k--) {
            int x, y;
            char o;
            cin >> x >> o >> y;
            int lll = 0, rrr = n;
            if (o == '>') lll = upper_bound(b[x] + 1, b[x] + n + 1, y) - b[x];
            else rrr = lower_bound(b[x] + 1, b[x] + n + 1, y) - b[x] - 1;
            l = max(lll, l), r = min(rrr, r);
            if (r - l < 0) break;
        }
        if (r - l < 0) cout << "-1\n";
        else cout << l << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--) solve();
}