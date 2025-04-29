/*
    author  : PakinDioxide
    created : 27/04/2025 06:21
    task    : 2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <pair <double, double>> a(n);
    double mnx = INT_MAX, mxx = INT_MIN, mny = INT_MAX, mxy = INT_MIN;
    for (auto &[x, y] : a) cin >> x >> y, mnx = min(mnx, x), mxx = max(mxx, x), mny = min(mny, y), mxy = max(mxy, y);
    double ans = (mxx-mnx)*(mxy-mny);
    cout << setprecision(12) << ans << '\n';    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}