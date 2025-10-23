/*
    author  : PakinDioxide
    created : 20/04/2025 00:21
    task    : 889
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7, mxN = 100;
vector <vector <ll>> mat(mxN, vector <ll>(mxN));

vector <vector <ll>> mult(vector <vector <ll>> a, vector <vector <ll>> b) {
    int n = a.size(), l = a[0].size(), m = b[0].size();
    vector <vector <ll>> c(n, vector <ll>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        for (int k = 0; k < l; k++) c[i][j] += (a[i][k] * b[k][j]) % mod, c[i][j] %= mod;
    }
    return c;
}

vector <vector <ll>> poww(vector <vector <ll>> a, ll x) {
    if (x == 1) return a;
    vector <vector <ll>> k = poww(a, x/2);
    k = mult(k, k);
    if (x % 2 == 1) k = mult(k, a);
    return k;
}

int countWays(ll n, int m, std::vector<int> a) {
    for (auto &e : a) mat[e-1][0] = 1;
    for (int j = 1; j < mxN; j++) mat[j-1][j] = 1;
    vector <vector <ll>> st(mxN, vector <ll>(mxN));
    st[0][0] = 1;
    return mult(st, poww(mat, n))[0][0];
}