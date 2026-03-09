#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

const int mxN = 2e5+5;
const int mod = 998244353;

vector <int> P;

bool is_prime(int x) {
    if (x < 2) return 0;
    if (x == 2) return 1;
    for (auto &e : P) {
        if (e * e > x) break;
        if (x % e == 0) return 0;
    }
    return 1;
}

ll poww(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll k = poww(x, y/2, m);
    k *=k, k %= m;
    if (y % 2 == 1) k *= x, k %= m;
    return k;
}

void solve() {
    int n, k; cin >> n >> k;
    int a[n];
    vector <int> cc[n];
    int ttamx = 0;
    int c[7][mxN]; memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        auto &e = a[i];
        cin >> e;
        for (auto &x : P) {
            if (x * x > e) break;
            if (e % x == 0) cc[i].emplace_back(x);
            while (e % x == 0) e /= x;
        }
        if (e > 1) cc[i].emplace_back(e);
        // for (auto &x : cc[i]) cout << x << ' ';
        // cout << '\n';
        int sz = cc[i].size();

        
        for (int x = 0; x <= 6; x++) {
            int t = 0;
            int l[7]; memset(l, 0, sizeof(l));
            for (int i = (1 << sz) - 1; i >= 0; i--) {
                int x = 1, xx = 0;
                for (int j = 0; j < sz; j++) if (i & (1 << j)) xx++, x *= cc[i][j];
                int tt = c[x][j];
                for (int kk = xx+1; kk <= sz; xx++) tt -= l[kk];
                l[xx] += tt;
            }
            for (int i = 0; i < 7; i++) ttamx += l[i] * poww(sz + x - i, k, mod), ttamx %= mod;
        }

        for (int i = 0; i < (1 << sz); i++) {
            int x = 1;
            for (int j = 0; j < sz; j++) if (i & (1 << j)) x *= cc[i][j];
            c[sz][x]++;
        }
    }
    cout << ttamx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 2; i <= 2e5; i++) if (is_prime(i)) P.emplace_back(i);//
    // int x = 1, cc = 0;
    // for (auto &e : P) {
    //     if (x * e > 2e5) break;
    //     x *= e;
    //     cc++;
    // }
    // cout << cc << '\n';
    int t; cin >> t;
    while (t--) solve();
}

/*
we should downgrade the number first

there are at most log2(n) = 6 factors

computing x = intersect(a_i, a_j) takes log2(n) time = 18

(c_i + c_j - x_ij)^k

you cant binomial theorem

x^k - d = (x-1)^k

*/