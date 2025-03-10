#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
ll seg[600005], laz[600005], sett[600005], a[200005];
int n, q;
 
void build(int l, int r, int node) {
    if (l == r) seg[node] = a[l];
    else {
        int mid = (l+r)/2;
        build(l, mid, node*2+1), build(mid+1, r, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}
 
ll sum(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = (l+r)/2;
        if (sett[node]) {
            sett[node*2+1] = sett[node*2+2] = sett[node];
            seg[node*2+1] = (mid-l+1)*sett[node];
            seg[node*2+2] = (r-mid)*sett[node];
            laz[node*2+1] = laz[node*2+2] = sett[node] = 0;
        }
        laz[node*2+1] += laz[node];
        laz[node*2+2] += laz[node];
        seg[node*2+1] += (mid-l+1)*laz[node];
        seg[node*2+2] += (r-mid)*laz[node];
        laz[node] = 0;
        ll k = 0;
        if (mid >= x) k += sum(l, mid, x, y, node*2+1);
        if (mid+1 <= y) k += sum(mid+1, r, x, y, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
        return k;
    }
}
 
void inc(int l, int r, int x, int y, ll k, int node) {
    if (x <= l && r <= y) seg[node] += (r-l+1)*k, laz[node] += k;
    else {
        int mid = (l+r)/2;
        if (sett[node]) {
            sett[node*2+1] = sett[node*2+2] = sett[node];
            seg[node*2+1] = (mid-l+1)*sett[node];
            seg[node*2+2] = (r-mid)*sett[node];
            laz[node*2+1] = laz[node*2+2] = sett[node] = 0;
        }
        laz[node*2+1] += laz[node];
        laz[node*2+2] += laz[node];
        seg[node*2+1] += (mid-l+1)*laz[node];
        seg[node*2+2] += (r-mid)*laz[node];
        laz[node] = 0;
        if (mid >= x) inc(l, mid, x, y, k, node*2+1);
        if (mid+1 <= y) inc(mid+1, r, x, y, k, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}
 
void upd(int l, int r, int x, int y, ll k, int node) {
    if (x <= l && r <= y) seg[node] = (r-l+1)*k, sett[node] = k, laz[node] = 0;
    else {
        int mid = (l+r)/2;
        if (sett[node]) {
            sett[node*2+1] = sett[node*2+2] = sett[node];
            seg[node*2+1] = (mid-l+1)*sett[node];
            seg[node*2+2] = (r-mid)*sett[node];
            laz[node*2+1] = laz[node*2+2] = sett[node] = 0;
        }
        laz[node*2+1] += laz[node];
        laz[node*2+2] += laz[node];
        seg[node*2+1] += (mid-l+1)*laz[node];
        seg[node*2+2] += (r-mid)*laz[node];
        laz[node] = 0;
        if (mid >= x) upd(l, mid, x, y, k, node*2+1);
        if (mid+1 <= y) upd(mid+1, r, x, y, k, node*2+2);
        seg[node] = seg[node*2+1] + seg[node*2+2];
    }
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r; ll x;
            cin >> l >> r >> x;
            inc(1, n, l, r, x, 0);
        } else if (t == 2) {
            int l, r; ll x;
            cin >> l >> r >> x;
            upd(1, n, l, r, x, 0);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sum(1, n, l, r, 0) << '\n';
        }
    }
}