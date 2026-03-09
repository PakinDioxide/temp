#include <bits/stdc++.h>
#define ll long long
#define M vector <vector <ll>>

// pasit GCC
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,fma,popcnt,lzcnt,bmi,bmi2,abm,sse4.2,f16c,movbe,fsgsbase,tune=native")

using namespace std;

const ll mod = 1e9+7;

int n, N;

M mult(M x, M y) {
    M z; z.resize(x.size()); for (auto &E : z) E.resize(y[0].size());
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < y[0].size(); j++) {
            for (int k = 0; k < x[0].size(); k++) {
                z[i][j] += (x[i][k] * y[k][j]) % mod;
                z[i][j] %= mod;
            }
        }
    }
    return z;
}

M I;

M poww(M x, ll y) {
    if (y == 0) return I;
    else if (y == 1) return x;
    else {
        M k = poww(x, y/2);
        k = mult(k, k);
        if (y % 2 == 1) k = mult(k, x);
        return k;
    }
}

void prnt(M X) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << X[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll l; int q; cin >> l >> n >> q;
    if (l == 0) { cout << 1 << '\n'; return 0; }
    N = 2*n+1;
    I.resize(N);
    for (auto &E : I) E.resize(N);
    for (int i = 0; i < N; i++) I[i][i] = 1;
    M X;
    X.resize(N);
    for (auto &E : X) E.resize(N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int A = i-n, B = j-n;
        X[i][j] = (abs(B - q*A) <= n);
    }
    // prnt(X);
    M O;
    O.resize(1);
    O[0].resize(N);
    for (auto &e : O[0]) e = 1;
    O = mult(O, poww(X, l-1));
    // prnt(poww(X, l-1));
    // for (auto &e : O[0]) cout << e << ' '; cout << '\n';
    ll ans = 0;
    for (int i = 0; i < N; i++) if (abs((i-n)*q) <= n) ans += O[0][i], ans %= mod;
    cout << ans << '\n';
}

