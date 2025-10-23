/*
    author  : PakinDioxide
    created : 30/03/2025 15:48
    task    : 1143
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll seg[800005], a[200005];

void build(int l, int r, int node) {
    if (l == r) seg[node] = a[l];
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}

int query(int l, int r, ll x, int node) {
    if (l == r) {seg[node] -= x; return l;}
    else {
        int mid = l + (r-l)/2, ans = 0;
        if (seg[node*2+1] >= x) ans = query(l, mid, x, node*2+1);
        else if (seg[node*2+2] >= x) ans = query(mid+1, r, x, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 0);
    while (q--) {
        ll x;
        cin >> x;
        if (seg[0] < x) {cout << 0 << ' '; continue;}
        cout << query(1, n, x, 0) << ' ';
    }
    cout << '\n';
}