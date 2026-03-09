#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1005;

int a[mxN][mxN];
ll UD[mxN][mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int j = 1; j <= m; j++) {
        ll s = 0;
        for (int i = 1; i <= n; i++) {
            UD[i][j] = s;
            s = max(s + a[i][j], (ll) a[i][j]);
        }
        s = 0;
        for (int i = n; i >= 1; i--) {
            UD[i][j] = max(UD[i][j], s);
            s = max(s + a[i][j], (ll) a[i][j]);
        }
    }
    ll ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        ll A[mxN], s = 0;
        for (int j = 1; j <= m; j++) {
            A[j] = s;
            s = max(s + a[i][j], (ll) a[i][j]);
        }
        s = 0;
        for (int j = m; j >= 1; j--) {
            A[j] = max(A[j], s);
            ans = max(ans, max(0LL, A[j]) + max(0LL, UD[i][j]) + a[i][j]);
            s = max(s + a[i][j], (ll) a[i][j]);
        }
    }
    cout << ans << '\n';
}

