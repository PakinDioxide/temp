/*
    author  : PakinDioxide
    created : 28/05/2025 21:08
    task    : 1739
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e3+5;

int n, q;
ll fen[mxN][mxN], a[mxN][mxN];

void upd(int x, int y, ll k) { for (int i = x; i <= n; i += i & -i) for (int j = y; j <= n; j += j & -j) fen[i][j] += k; }
ll qr(int x, int y) { ll k = 0; for (int i = x; i > 0; i -= i & -i) for (int j = y; j > 0; j -= j & -j) k += fen[i][j]; return k; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) { char x; cin >> x; a[i][j] = (x == '*'); upd(i, j, a[i][j]); }
    while (q--) {
        int t; cin >> t;
        if (t == 1) { int x, y; cin >> x >> y, upd(x, y, (!a[x][y]) - a[x][y]), a[x][y] = !a[x][y]; }
        else { int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; x1--, y1--; cout << qr(x2, y2) - qr(x2, y1) - qr(x1, y2) + qr(x1, y1) << '\n'; }
    }
}