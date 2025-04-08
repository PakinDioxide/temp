/*
    author  : PakinDioxide
    created : 14/03/2025 13:42
    task    : 2016_Opn_S_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto &e : a) cin >> e;
    sort(a, a+n);
    int mxl[n], mxr[n], l = 0, r = 0;
    for (r = 0; r < n; r++) {
        mxl[r] = 0;
        if (r > 0) mxl[r] = mxl[r-1];
        while (a[r] - a[l] > k) l++;
        mxl[r] = max(mxl[r], r-l+1);
    }
    l = 0, r = n-1;
    for (l = n-1; l >= 0; l--) {
        mxr[l] = 0;
        if (l < n-1) mxr[l] = mxr[l+1];
        while (a[r] - a[l] > k) r--;
        mxr[l] = max(mxr[l], r-l+1);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) ans = max(ans, mxl[i-1] + mxr[i]);
    cout << ans << '\n';
}