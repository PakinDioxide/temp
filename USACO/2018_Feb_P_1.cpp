/*
    author  : PakinDioxide
    created : 22/05/2025 21:32
    task    : 2018_Feb_P_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 4e5+5;
const ll mxK = 1e9+5;

struct T {
    ll x, y, t, q;
    bool operator<(const T &o) {
        return (x < o.x ? 1 : x == o.x ? y < o.y : 0);
    }
};

struct ST {
    ll seg[4*mxN];
    void build(int l, int r, int node) {
        if (l == r) seg[node] = LLONG_MAX;
        else {
            int mid = l + (r-l)/2;
            build(l, mid, node<<1);
            build(mid+1, r, node<<1|1);
            seg[node] = min(seg[node<<1], seg[node<<1|1]);
        }
    }
    void upd(int l, int r, int idx, ll x, int node) {
        if (l == r) seg[node] = (x == LLONG_MAX ? x : min(seg[node], x));
        else {
            int mid = l + (r-l)/2;
            if (mid >= idx) upd(l, mid, idx, x, node<<1);
            else upd(mid+1, r, idx, x, node<<1|1);
            seg[node] = min(seg[node<<1], seg[node<<1|1]);
        }
    }
    ll qr(int l, int r, int x, int y, int node) {
        if (x <= l && r <= y) return seg[node];
        else {
            int mid = l + (r-l)/2; ll k = LLONG_MAX;
            if (mid >= x) k = min(k, qr(l, mid, x, y, node<<1));
            if (mid+1 <= y) k = min(k, qr(mid+1, r, x, y, node<<1|1));
            return k;
        }
    }
};

int n, q, it = 0;
vector <T> A;
vector <ll> cmp;
ST seg[2];

int f(ll x) { return upper_bound(cmp.begin(), cmp.end(), x) - cmp.begin(); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("slingshot.in", "r", stdin);
    // freopen("slingshot.out", "w", stdout);
    cin >> n >> q;
    A.resize(n+q);
    for (int i = 0; i < n; i++) cin >> A[i].x >> A[i].y >> A[i].t, A[i].q = 1, cmp.emplace_back(A[i].x), cmp.emplace_back(A[i].y);
    for (int i = n; i < n+q; i++) cin >> A[i].x >> A[i].y, A[i].q = 0, cmp.emplace_back(A[i].x), cmp.emplace_back(A[i].y);
    sort(cmp.begin(), cmp.end());
    sort(A.begin(), A.end());
    seg[0].build(1, mxN, 1), seg[1].build(1, mxN, 1);
    for (auto &e : A) if (e.x > e.y) swap(e.x, e.y);
    for (auto &e : A) if (e.q) seg[0].upd(1, mxN, f(e.y), (mxK-e.y)+e.x+e.t, 1), seg[1].upd(1, mxN, f(e.y), e.y+e.x+e.t, 1);
    for (auto &e : A) {
        if (e.q) 
    }
}