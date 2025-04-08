/*
    author  : PakinDioxide
    created : 08/04/2025 17:37
    task    : 1753_hash
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const ll M = 1e9+7;
const ll A = uniform_int_distribution<ll>(0, M - 1)(rng);

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    ll h[n], p[n], k = 0, cnt = 0;
    h[0] = a[0], p[0] = 1;
    for (int i = 1; i < n; i++) h[i] = ((h[i-1]*A)%M + a[i])%M, p[i] = (p[i-1]*A)%M;
    for (int i = 0; i < m; i++) k = ((k*A)%M + b[i])%M;
    for (int l = 0; l+m-1 < n; l++) {
        int r = l+m-1;
        cnt += (k == (h[r] - (((l == 0 ? 0 : h[l-1])*(p[r-l+1])) % M) + M) % M);
    }
    cout << cnt << '\n';
}