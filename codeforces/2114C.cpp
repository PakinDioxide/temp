/*
    author  : PakinDioxide
    created : 26/05/2025 21:43
    task    : 2114C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 4e5+5;

int fen[mxN];

void rst() {memset(fen, 0, sizeof(fen));}
void upd(int idx, int x) {for (int i = idx; i < mxN; i += i & -i) fen[i] = max(fen[i], x); }
int qr(int idx) {int x = 0; for (int i = idx; i > 0; i -= i & -i) x = max(x, fen[i]); return x;}

void solve() {
    vector <int> cmp;
    int n; cin >> n; int a[n]; for (auto &e : a) cin >> e, cmp.emplace_back(e), cmp.emplace_back(e-2);
    sort(cmp.begin(), cmp.end());
    rst();
    for (auto &e : a) {
        upd(upper_bound(cmp.begin(), cmp.end(), e) - cmp.begin(), qr(upper_bound(cmp.begin(), cmp.end(), e-2) - cmp.begin())+1);
    }
    cout << qr(mxN-1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}