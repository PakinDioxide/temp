#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5, mxM = 1e5+5;
const ll mod = 1e9+7;

int n, m, s, q, vis[mxM], p[3][mxN], T[mxN];
ll seg[2][4*mxN], qx[mxN+mxM];

void build(int l, int r, int node) {
    if (l == r) seg[0][node] = T[l], seg[1][node] = T[l];
    else {
        int mid = l + (r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[0][node] = min(seg[0][node*2+1], seg[0][node*2+2]);
        seg[1][node] = max(seg[1][node*2+1], seg[1][node*2+2]);
    }
}

pair <int, int> qr(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return make_pair(seg[0][node], seg[1][node]);
    else {
        int mid = l + (r-l)/2;
        pair <ll, ll> k = make_pair(LLONG_MAX, LLONG_MIN), t;
        if (mid >= x) t = qr(l, mid, x, y, node*2+1), k.first = min(k.first, t.first), k.second = max(k.second, t.second);
        if (mid+1 <= y) t = qr(mid+1, r, x, y, node*2+2), k.first = min(k.first, t.first), k.second = max(k.second, t.second);
        return k;
    }
}

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;    
}

ll inv(ll x) { return poww(x, mod-2); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> s;
    qx[0] = 1;
    for (int i = 0; i < n+m; i++) qx[i+1] = (((qx[i] * (n+m-i)) % mod) * inv(i+1)) % mod;
    // qn[0] = qm[0] = 1;
    // for (int i = 0; i < n; i++) qn[i+1] = (((qn[i] * (n-i)) % mod) * inv(i+1)) % mod;
    // for (int i = 0; i < m; i++) qm[i+1] = (((qm[i] * (m-i)) % mod) * inv(i+1)) % mod;
    for (int i = 0, x; i < s; i++) cin >> x, vis[x] = 1;
    for (int i = 1; i <= n; i++) {
        p[0][i] = p[0][i-1], p[1][i] = p[1][i-1], p[2][i] = p[2][i-1];
        cin >> T[i];
        ll G = __gcd(i, n), R = T[i] % m;
        if (G > 1 && vis[R]) p[0][i]++;
        else if (G == 1 && !vis[R]) p[1][i]++;
        else p[2][i]++;
    }
    build(1, n, 0);
    cin >> q;
    while (q--) {
        int l, r, t; cin >> l >> r >> t;
        pair <ll, ll> k = qr(1, n, l, r, 0);
        cout << p[0][r] - p[0][l-1] << ' ' << p[1][r] - p[1][l-1] << ' ' << p[2][r] - p[2][l-1] << ' ' << k.second - k.first << ' ';
        if (t) {
            int sx = max({p[0][r] - p[0][l-1], p[1][r] - p[1][l-1], p[2][r] - p[2][l-1]});
            // ll s = 0;
            // for (int i = 0; i <= sx; i++) s += (qn[i] * qm[sx-i]) % mod, s %= mod;
            // cout << s;
            cout << qx[sx];
        }
        cout << '\n';
    }
}