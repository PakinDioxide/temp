/*
    author  : PakinDioxide
    created : 25/04/2025 20:25
    task    : JOI19_ho_t2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair <ll, ll> A[n];
    ll a[n], b[m];
    for (auto &[x, y] : A) cin >> y >> x;
    for (auto &e : b) cin >> e;
    sort(b, b+m);
    sort(A, A+n);
    for (int i = 0; i < n; i++) a[n-i-1] = A[i].second;
    int ans = 0, idx = m-1; ll mn = LLONG_MAX;
    for (auto &e : a) {
        mn = min(mn, e);
        if (mn <= b[idx]) idx--, mn = LLONG_MAX, ans++;
        if (idx < 0) break;
    }
    cout << ans << '\n';
}