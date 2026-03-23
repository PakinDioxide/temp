#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;
const ll mod = 998244353;

ll a[mxN], inv[mxN];

ll cross(complex <long double> x, complex <long double> y) {
    return imag((conj(x)*y));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    for (int i = 1; i <= n; i++) cin >> a[i];
    deque <int> dq;
    int sz = 0;
    for (int i = 1; i <= n; i++) {
        while (sz >= 2 && cross({dq[sz-1] - dq[sz-2], a[dq[sz-1]] - a[dq[sz-2]]}, {i - dq[sz-1], a[i] - a[dq[sz-1]]}) >= 0) dq.pop_back(), sz--;
        dq.emplace_back(i), sz++;
    }
    int L[n+1], R[n+1];
    for (int i = 1; i <= n; i++) {
        L[i] = *prev(upper_bound(dq.begin(), dq.end(), i));
        R[i] = *lower_bound(dq.begin(), dq.end(), i);
    }
    ll ANS = 0;
    for (int i = 1; i <= n; i++) {
        if (L[i] == i || R[i] == i) { ANS += a[i], ANS %= mod; continue; }
        ll P = (a[R[i]] * (i - L[i])) % mod;
        ll Q = (a[L[i]] * (R[i] - i)) % mod;
        ll Res = (P + Q) % mod;
        Res *= inv[R[i]-L[i]], Res %= mod;
        ANS += Res, ANS %= mod;
    }
    ANS *= inv[n], ANS %= mod;
    cout << ANS << '\n';
}

