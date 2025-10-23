#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, fen[mxN], a[mxN], b[mxN], pos[mxN];

void upd(int idx, int x) { for (int i = idx; i <= n; i += i & -i) fen[i] = max(fen[i], x); }
int qr(int idx) { int x = 0; for (int i = idx; i > 0; i -= i & -i) x = max(x, fen[i]); return x; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = i;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        vector <pair <int, int>> v;
        for (int j = max(1, b[i] - 4); j <= min(n, b[i] + 4); j++) {
            v.emplace_back(pos[j], qr(pos[j]-1) + 1);
        }
        for (auto &[x, y] : v) upd(x, y);
    }
    cout << qr(n) << '\n';
}

/*
we have 2 rows,

we loop through the lower row, updating the upper row's value.

if we want to connect to the upper row at index i

the value will be v[i-1] + 1

then we update max for all right from i to n

we get the index on the upper row for each value first

then loop to x - 4 to x + 4

use fenwick to update the value

1 2 3 4 5 6
6 5 4 3 2 1
*/