/*
    author  : 
    created : 02/07/2025 20:35
    task    : 2087
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3005;

ll p[mxN], q[mxN], a[mxN], n, k, g[mxN][mxN], f[mxN][mxN];

ll calcg(ll x, ll j, ll c) {
    return -j*x + (j*q[j]-p[j]+f[j][c]);
}
ll calcf(ll x, ll j, ll c) {
    return -q[j]*x + (p[j]+g[j][c-1]);
}
long double mf(ll x, ll y, ll c) {
    return (long double) (calcf(0, x, c)-calcf(0, y, c))/((-q[y])-(-q[x]));
}
long double mg(ll x, ll y, ll c) {
    return (long double) (calcg(0, x, c)-calcg(0, y, c))/((-y)-(-x));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i-1] + a[i] * i, q[i] = q[i-1] + a[i];
    for (int c = 1; c <= k; c++) {
        if (c == 1) {
            for (int i = 1; i <= n; i++) f[i][c] = calcf(i, 0, c) + i*q[i] - p[i];
        } else {
            deque <int> cht; cht.emplace_back(0);
            for (int i = 1; i <= n; i++) {
                while (cht.size() > 1 && calcf(i, cht[0], c) > calcf(i, cht[1], c)) cht.pop_front();
                f[i][c] = calcf(i, cht[0], c) + i*q[i] - p[i];
                while (cht.size() > 1 && mf(cht[cht.size()-1], i, c) <= mf(cht[cht.size()-2], cht[cht.size()-1], c)) cht.pop_back();
                cht.emplace_back(i);
            }
        }
        deque <int> cht; cht.emplace_back(0);
        for (int i = 1; i <= n; i++) {
            while (cht.size() > 1 && calcg(q[i], cht[0], c) > calcg(q[i], cht[1], c)) cht.pop_front();
            g[i][c] = calcg(q[i], cht[0], c) + p[i];
            g[i][c] = min(g[i][c], f[i][c]);
            while (cht.size() > 1 && mg(cht[cht.size()-1], i, c) <= mg(cht[cht.size()-2], cht[cht.size()-1], c)) cht.pop_back();
            cht.emplace_back(i);
        }
    }
    cout << min(f[n][k], g[n][k]) << '\n';
}