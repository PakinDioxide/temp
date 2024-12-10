#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Node{
    ll g, l, r, s;
    Node operator+(Node b) {
        return {max({g, b.g, r + b.l}), max(l, s + b.l), max(b.r, r + b.s), s + b.s};
    }
};

ll a[200005];
Node seg[1000000];

void build(ll node, ll l, ll r) {
    if (l == r) {
        seg[node] = {max(0ll, a[l]), max(0ll, a[l]), max(0ll, a[l]), a[l]};
    } else {
        build(node*2, l, (l+r)/2);
        build(node*2+1, (l+r)/2+1, r);
        seg[node] = seg[node*2] + seg[node*2+1];
    }
}

void upd(ll node, ll l, ll r, ll x, ll y) {
    if (l == r) {
        seg[node] = {max(0ll, y), max(0ll, y), max(0ll, y), y};
    } else {
        ll mid = (l+r)/2;
        if (x <= mid) upd(node*2, l, mid, x, y);
        else upd(node*2+1, mid+1, r, x, y);
        seg[node] = seg[node*2] + seg[node*2+1];
    }
}

int main() {
    ll n, q;
    scanf("%lld %lld", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    build(1, 1, n);
    while (q--) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        upd(1, 1, n, x, y);
        printf("%lld\n", seg[1].g);
    }
}