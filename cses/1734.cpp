/*
    author  : PakinDioxide
    created : 07/04/2025 22:59
    task    : 1734
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
int n, q, fen[mxN], a[mxN], ans[mxN];
vector <pair <int, int>> Q[mxN];
map <int, int> mnidx;

void upd(int idx, int x) { for (int i = idx; i <= n; i += i & -i) fen[i] += x; }
int qr(int idx) { int k = 0; for (int i = idx; i > 0; i -= i & -i) k += fen[i]; return k; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) { int l, r; cin >> l >> r; Q[l].emplace_back(r, i); }
    for (int i = n; i >= 1; i--) {
        if (mnidx[a[i]] > 0) upd(mnidx[a[i]], -1);
        upd(mnidx[a[i]] = i, 1);
        for (auto &[r, idx] : Q[i]) ans[idx] = qr(r);
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}