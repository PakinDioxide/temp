/*
    author  : PakinDioxide
    created : 27/03/2025 17:53
    task    : 1722
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

vector <ll> mult(vector <ll> a, vector <ll> b) {
    return {(a[0]*b[0] + a[1]*b[2]) % mod, (a[0]*b[1] + a[1]*b[3]) % mod, (a[2]*b[0] + a[3]*b[2]) % mod, (a[2]*b[1] + a[3]*b[3]) % mod};
}

vector <ll> poww(vector <ll> m, ll k) {
    if (k == 1) return m;
    vector <ll> x = poww(m, k/2);
    x = mult(x, x);
    if (k % 2 == 1) x = mult(x, m);
    return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    if (n == 0) {cout << 0 << '\n'; return 0;}
    cout << poww({1, 1, 1, 0}, n)[1] << '\n';
}