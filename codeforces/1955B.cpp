#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;
        int a[n*n], mi = INT_MAX;
        map <int, int> k;
        for (int i = 0; i < n*n; i++) {cin >> a[i]; k[a[i]]++; mi = min(mi, a[i]);}
        int aa[n][n], ok = 1;
        aa[0][0] = mi;
        for (int i = 1; i < n; i++) {
            aa[i][0] = aa[i-1][0] + c;
            if (k[aa[i][0]] <= 0) {ok = 0; break;}
            k[aa[i][0]]--;
            aa[0][i] = aa[0][i-1] + d;
            if (k[aa[0][i]] <= 0) {ok = 0; break;}
            k[aa[0][i]]--;
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        for (int i = 1; i < n; i++) for (int j = 1; j < n; j++) {
            if (aa[i-1][j] + c != aa[i][j-1] + d || k[aa[i-1][j] + c] <= 0) {
                ok = 0;
                break;
            } else {k[aa[i-1][j] + c]--; aa[i][j] = aa[i-1][j] + c;}
            if (!ok) break;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}