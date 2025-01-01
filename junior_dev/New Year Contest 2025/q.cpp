// PakinDioxide
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 998244353, n, m, seg[800005], laz[800005], idc[800005], ic[800005], sz[800005];

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2) % mod;
    k*=k, k %= mod;
    if (y%2) k*=x, k %= mod;
    return k;
}

void build(int l, int r, int node) {
    if (l == r) seg[node] = 0, sz[node] = 1, ic[node] = 1;
    else {
        int mid = (l+r)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        idc[node*2+1] = poww(10, r-mid);
        // cout << l << ' ' << mid << ' ' << r << ' ' << idc[node*2+1] << '\n';
        seg[node] = seg[node*2+1] + seg[node*2+2];
        sz[node] = sz[node*2+1] + sz[node*2+2];
        ic[node] = ((ic[node*2+1] * idc[node*2+1])%mod + ic[node*2+2]) % mod;
    }
}

void psh(int node) {
    if (laz[node] == 0) return;
    laz[node*2+1] = laz[node*2+2] = laz[node];
    seg[node] = (ic[node] * laz[node])%mod;
    laz[node] = 0;
}

void st(int l, int r, int node, int x, int y, int k) {
    if (r < x || l > y) {psh(node); return;}
    if (x <= l && r <= y) {
        laz[node] = k;
        psh(node);
    } else {
        psh(node);
        int mid = (l+r)/2;
        st(l, mid, node*2+1, x, y, k);
        st(mid+1, r, node*2+2, x, y, k);
        seg[node] = ((idc[node*2+1] * seg[node*2+1])%mod + seg[node*2+2])%mod;
        // cout << node << ' ' << idc[node*2+1] << ' ' << seg[node*2+1] << ' '<< seg[node*2+2] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    build(1, n, 0);
    while (m--) {
        int l, r, d;
        cin >> l >> r >> d;
        l = n-l+1, r = n-r+1;
        swap(l, r);
        st(1, n, 0, l, r, d);
        string ans = "";
        ll k = seg[0];
        while (k > 0) ans += '0' + (k % 10), k/=10;
        while (ans.size() < 9) ans += '0';
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}