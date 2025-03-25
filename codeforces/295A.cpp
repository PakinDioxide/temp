/*
    author  : PakinDioxide
    created : 14/03/2025 13:23
    task    : 295A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    ll A[n];
    for (auto &e : A) cin >> e;
    tuple <int, int, ll> a[m];
    for (auto &[l, r, x] : a) cin >> l >> r >> x;
    ll ans[n+2], cnt[m+2];
    memset(cnt, 0, sizeof(cnt));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r+1]--;
    }
    ll sum = 0;
    for (int i = 1; i <= m; i++) {
        sum += cnt[i];
        auto [l, r, x] = a[i-1];
        ans[l] += sum * x;
        ans[r+1] -= sum * x;
    }
    sum = 0;
    for (int i = 1; i <= n; i++) sum += ans[i], cout << sum + A[i-1] << ' ';
    cout << '\n';
}