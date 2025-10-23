/*
    author  : 
    created : 03/07/2025 00:02
    task    : 166E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7;

vector <vector <ll>> init = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}, k = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}}, one = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

vector <vector <ll>> mul(vector <vector <ll>> a, vector <vector <ll>> b) {
    vector <vector <ll>> c(4, vector <ll>(4));
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++) c[i][j] += a[i][k]*b[k][j], c[i][j] %= mod;
    return c;
}

vector <vector <ll>> poww(int n) {
    if (n == 0) return one;
    vector <vector <ll>> x = poww(n/2); x = mul(x, x);
    if (n % 2 == 1) x = mul(x, k);
    return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    cout << mul(init, poww(n))[0][0] << '\n';
}