/*
    author  : 
    created : 25/06/2025 19:13
    task    : 1748
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;
const ll mod = 1e9+7;

ll fen[mxN], ans = 0;

void upd(int idx, ll x) { for (int i = idx; i < mxN; i += i & -i) fen[i] = (fen[i] + x) % mod; }
ll qr(int idx) { ll k = 0; for (int i = idx; i > 0; i -= i & -i) k = (fen[i] + k) % mod; return k;}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <ll> cmp; ll a[n];
    for (auto &e : a) cin >> e, cmp.emplace_back(e);
    sort(cmp.begin(), cmp.end());
    for (auto &e : a) e = upper_bound(cmp.begin(), cmp.end(), e) - cmp.begin() + 1;
    upd(1, 1);
    for (auto &e : a) {
        ll k = qr(e-1);
        ans = (ans + k) % mod;
        upd(e, k);
    }
    cout << ans << '\n';
}