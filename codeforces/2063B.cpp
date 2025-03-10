#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    ll a[n+1], sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <ll> L, R, M;
    for (int i = 1; i < l; i++) L.push_back(a[i]);
    for (int i = l; i <= r; i++) M.push_back(-a[i]), sum += a[i], ans += a[i];
    for (int i = r+1; i <= n; i++) R.push_back(a[i]);
    sort(L.begin(), L.end()), sort(R.begin(), R.end()), sort(M.begin(), M.end());
    ll x = 0, y = 0, sx = 0, sy = 0;
    while (x < L.size() & y < M.size()) {
        sx += L[x], sy -= M[y];
        ans = min(ans, sum - sy + sx);
        x++, y++;
    }
    x = 0, y = 0, sx = 0, sy = 0;
    while (x < R.size() & y < M.size()) {
        sx += R[x], sy -= M[y];
        ans = min(ans, sum - sy + sx);
        x++, y++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}