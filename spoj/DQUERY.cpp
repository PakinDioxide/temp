/*
    author  : PakinDioxide
    created : 11/05/2025 01:03
    task    : DQUERY
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3e4+5, mxV = 1e6+5, mxQ = 2e5+5;

int n, q, sz, a[mxN], cnt[mxV], ans[mxQ];
vector <tuple <int, int, int, int>> Q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n; sz = sqrt(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--, r--;
        Q.emplace_back(l/sz, r, l, i);
    }
    sort(Q.begin(), Q.end());
    int L = -1, R = -1, c = 0;
    for (auto &[b, r, l, idx] : Q) {
        while (L > l) L--, c += (++cnt[a[L]] == 1);
        while (L < l) c -= (--cnt[a[L]] == 0), L++;
        while (R < r) R++, c += (++cnt[a[R]] == 1);
        while (R > r) c -= (--cnt[a[R]] == 0), R--;
        ans[idx] = c;
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}