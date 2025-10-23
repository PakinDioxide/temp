/*
    author  : 
    created : 17/06/2025 21:42
    task    : 2121C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int a[n+1][m+1], p[4][n+2][m+2], r[n+2], c[m+2];
    memset(a, 0, sizeof(a)), memset(p, 0, sizeof(p)), memset(r, 0, sizeof(r)), memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j], r[i] = max(r[i], a[i][j]), c[j] = max(c[j], a[i][j]);
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) p[0][i][j] = max({p[0][i-1][j], p[0][i][j-1], a[i][j]});
    for (int i = 1; i <= n; i++) for (int j = m; j >= 1; j--) p[1][i][j] = max({p[1][i-1][j], p[1][i][j+1], a[i][j]});
    for (int i = n; i >= 1; i--) for (int j = 1; j <= m; j++) p[2][i][j] = max({p[2][i+1][j], p[2][i][j-1], a[i][j]});
    for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) p[3][i][j] = max({p[3][i+1][j], p[3][i][j+1], a[i][j]});
    
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) mn = min(mn, max({r[i]-1, c[j]-1, p[0][i-1][j-1], p[1][i-1][j+1], p[2][i+1][j-1], p[3][i+1][j+1]}));
    cout << mn << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}