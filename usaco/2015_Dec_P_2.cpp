/*
    author  : PakinDioxide
    created : 21/05/2025 01:24
    task    : 2015_Dec_P_2
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

struct T {
    int A, B, S;
};

int n, N, vis[mxN], mx = 0;
vector <int> P, Q;
T seg[2][4*mxN];

T add(const T &a, const T &b, const int &k) {
    int c;
    if (k == 0) c = min(a.A, b.B);
    else c = min(a.B, b.A);
    return {a.A+b.A-c, a.B+b.B-c, a.S+b.S+c};
}

void upd(int l, int r, int idx, T x, int node, int k) {
    if (l == r) seg[k][node] = x;
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, idx, x, node<<1, k);
        else upd(mid+1, r, idx, x, node<<1|1, k);
        seg[k][node] = add(seg[k][node<<1], seg[k][node<<1|1], k);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin >> n; N = n<<1;
    P.resize(n);
    for (auto &e : P) cin >> e, vis[e] = 1;
    for (int i = 1; i <= N; i++) upd(1, N, i, T{vis[i], !vis[i], 0}, 1, 0);
    for (int i = N; i >= 1; i--) if (!vis[i]) Q.emplace_back(i);
    mx = seg[0][1].S;
    for (int i = n-1; i >= 0; i--) {
        upd(1, N, P[i], T{0, 0, 0}, 1, 0);
        upd(1, N, P[i], T{1, 0, 0}, 1, 1);
        upd(1, N, Q[i], T{0, 0, 0}, 1, 0);
        upd(1, N, Q[i], T{0, 1, 0}, 1, 1);
        mx = max(mx, seg[0][1].S + seg[1][1].S);
    }
    cout << mx << '\n';
}