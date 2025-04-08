/*
    author  : PakinDioxide
    created : 08/04/2025 00:58
    task    : 2020_Opn_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree <T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN = 1e5+5;
ll fen[mxN], n, e;
Tree <int> s;

void upd(int idx, int x) { for (int i = idx; i <= n; i += i & -i) fen[i] += x; }
ll qr(int idx) { ll k = 0; for (int i = idx; i > 0; i -= i & -i) k += fen[i]; return k; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> e;
        if (e < n-1) upd(e+1, s.size() - s.order_of_key(e+1));
        s.insert(e);
    }
    for (int i = 0; i < n; i++) cout << qr(i) << '\n';
}

/*
we consider at idx = i
let x = a[i]

for all j > x, the inversion count will be the same
else the inversion count will be zero

*/