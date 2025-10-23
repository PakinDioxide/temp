#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
ll seg[800005], laz[800005], a[200005], p[200005], fen[200005];
int n, q;
 
void uf(int idx, ll x) {
    for (int i = idx; i <= n; i += (i & (-i))) fen[i] += x;
}
 
ll sf(int idx) {
    ll sum = 0;
    for (int i = idx; i > 0; i -= (i & (-i))) sum += fen[i];
    return sum;
}
 
void build(int l, int r, int node) {
    if (l == r) seg[node] = p[l];
    else {
        int mid = (l+r)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}
 
void push(int node) {
    seg[node*2+1] += laz[node];
    seg[node*2+2] += laz[node];
    laz[node*2+1] += laz[node];
    laz[node*2+2] += laz[node];
    laz[node] = 0;
}
 
void upd(int l, int r, int x, int y, ll k, int node) {
    if (x <= l && r <= y) seg[node] += k, laz[node] += k;
    else {
        push(node);
        int mid = (l+r)/2;
        if (mid >= x) upd(l, mid, x, y, k, node*2+1);
        if (mid+1 <= y) upd(mid+1, r, x, y, k, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}
 
ll sum(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        push(node);
        int mid = (l+r)/2;
        ll k = LLONG_MIN;
        if (mid >= x) k = max(k, sum(l, mid, x, y, node*2+1));
        if (mid+1 <= y) k = max(k, sum(mid+1, r, x, y, node*2+2));
        return k;
    }
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    a[0] = p[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = a[i] + p[i-1], uf(i, a[i]);
    build(1, n, 0);
    while (q--) {
        int t, u;
        ll v;
        cin >> t >> u >> v;
        if (t == 1) upd(1, n, u, n, v-a[u], 0), uf(u, v-a[u]), a[u] = v;
        else cout << max(0LL, sum(1, n, u, v, 0) - sf(u-1)) << '\n';
    }
}