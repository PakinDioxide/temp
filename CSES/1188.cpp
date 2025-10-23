/*
    author  : PakinDioxide
    created : 20/05/2025 00:15
    task    : 1188
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 2e5+5;

struct T {
    ll vL, vR, L, R, M, S;
};

int n, q;
string s;
T seg[4*mxN];

void mg(int p, int u, int v) {
    seg[p].vL = seg[u].vL;
    seg[p].vR = seg[v].vR;
    seg[p].L = max(seg[u].L, (seg[u].L == seg[u].S && seg[u].vR == seg[v].vL ? seg[u].L + seg[v].L : 0));
    seg[p].R = max(seg[v].R, (seg[v].R == seg[v].S && seg[u].vR == seg[v].vL ? seg[v].R + seg[u].R : 0));
    seg[p].M = max({seg[p].L, seg[p].R, seg[u].M, seg[v].M, (seg[u].vR == seg[v].vL ? seg[u].R + seg[v].L : 0)});
    seg[p].S = seg[u].S + seg[v].S;
}

void upd(int l, int r, int idx, ll x, int node) {
    if (l == r) seg[node] = {x, x, 1, 1, 1, 1};
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, x, node<<1);
        else upd(mid+1, r, idx, x, node<<1|1);
        mg(node, node<<1, node<<1|1);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) s[i] = (s[i] == '1'), upd(0, n-1, i, s[i], 1);
    cin >> q;
    while (q--) {
        int idx; cin >> idx; idx--;
        s[idx] ^= 1;
        upd(0, n-1, idx, s[idx], 1);
        cout << seg[1].M << ' ';
    }
    cout << '\n';
}