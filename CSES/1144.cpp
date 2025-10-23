/*
    author  : PakinDioxide
    created : 11/04/2025 09:35
    task    : 1144
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

ll n, q, a[mxN], fen[4*mxN];
vector <ll> cmp;
tuple <char, ll, ll> Q[mxN];

void upd(int idx, ll x) { for (int i = idx; i <= cmp.size(); i += i & -i) fen[i] += x; }
ll qr(int idx) { ll s = 0; for (int i = idx; i > 0; i -= i & -i) s += fen[i]; return s; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], cmp.emplace_back(a[i]);
    for (int i = 0; i < q; i++) { auto &[x, l, r] = Q[i]; cin >> x >> l >> r; if (x == '?') cmp.emplace_back(l); cmp.emplace_back(r); }
    sort(cmp.begin(), cmp.end());
    for (int i = 1; i <= n; i++) a[i] = upper_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin(), upd(a[i], 1);
    for (int i = 0; i < q; i++) {
        auto &[x, l, r] = Q[i]; if (x == '?') l = upper_bound(cmp.begin(), cmp.end(), l) - cmp.begin(); r = upper_bound(cmp.begin(), cmp.end(), r) - cmp.begin();
        if (x == '?') cout << qr(r) - qr(l-1) << '\n';
        else upd(a[l], -1), a[l] = r, upd(a[l], 1);
    }
}