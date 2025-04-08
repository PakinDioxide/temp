/*
    author  : PakinDioxide
    created : 01/04/2025 17:42
    task    : 1648_sqrt
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll a[200005], blk[1000], sz;

void upd(int idx, ll x) {
    blk[idx / sz] -= a[idx];
    a[idx] = x;
    blk[idx / sz] += a[idx];
}

ll qr(int idx) {
    ll sum = 0;
    for (int i = 0; i < idx / sz; i++) sum += blk[i];
    for (int i = (idx / sz) * sz; i <= idx; i++) sum += a[i];
    return sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    sz = sqrt(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        upd(i, x);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx; ll x;
            cin >> idx >> x;
            idx--;
            upd(idx, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << qr(r) - qr(l-1) << '\n';
        }
    }
}