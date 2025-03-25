/*
    author  : PakinDioxide
    created : 20/03/2025 12:46
    task    : 2016_Opn_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    int n;
    cin >> n;
    pair <ll, ll> a[n];
    ll mnx = LLONG_MAX, mxx = 0, mny = LLONG_MAX, mxy = 0;
    for (auto &[x, y] : a) cin >> x >> y, mnx = min(mnx, x), mxx = max(mxx, x), mny = min(mny, y), mxy = max(mxy, y);
    ll ans = LLONG_MAX;
    ll mnl[n], mxl[n], mnr[n], mxr[n];
    sort(a, a+n);
    mnl[0] = mxl[0] = a[0].second, mnr[n-1] = mxr[n-1] = a[n-1].second;
    for (int i = 1; i < n; i++) mnl[i] = min(mnl[i-1], a[i].second), mxl[i] = max(mxl[i-1], a[i].second);
    for (int i = n-2; i > 0; i--) mnr[i] = min(mnr[i+1], a[i].second), mxr[i] = max(mxr[i+1], a[i].second);
    for (int i = 0; i < n-1; i++) {
        if (a[i].first == a[i+1].first) continue;
        ans = min(ans, (a[i].first - a[0].first) * (mxl[i] - mnl[i]) + (a[n-1].first - a[i+1].first) * (mxr[i+1] - mnr[i+1]));
        // cout << i << ' ' << (a[i].first - a[0].first) * (mxl[i] - mnl[i]) << ' ' << (a[n-1].first - a[i+1].first) * (mxr[i+1] - mnr[i+1]) << '\n';
    }
    for (auto &[x, y] : a) swap(x, y);
    sort(a, a+n);
    mnl[0] = mxl[0] = a[0].second, mnr[n-1] = mxr[n-1] = a[n-1].second;
    for (int i = 1; i < n; i++) mnl[i] = min(mnl[i-1], a[i].second), mxl[i] = max(mxl[i-1], a[i].second);
    for (int i = n-2; i > 0; i--) mnr[i] = min(mnr[i+1], a[i].second), mxr[i] = max(mxr[i+1], a[i].second);
    for (int i = 0; i < n-1; i++) {
        if (a[i].first == a[i+1].first) continue;
        ans = min(ans, (a[i].first - a[0].first) * (mxl[i] - mnl[i]) + (a[n-1].first - a[i+1].first) * (mxr[i+1] - mnr[i+1]));
        // cout << i << ' ' << (a[i].first - a[0].first) * (mxl[i] - mnl[i]) << ' ' << (a[n-1].first - a[i+1].first) * (mxr[i+1] - mnr[i+1]) << '\n';
    }
    cout << (mxx - mnx) * (mxy - mny) - ans << '\n';
}