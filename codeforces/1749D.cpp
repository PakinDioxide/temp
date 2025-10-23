/*
    author  : 
    created : 21/09/2025 22:35
    task    : 1749D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 998244353;

vector <ll> PRIME;

bool prime(ll x) {
    for (auto &e : PRIME) {
        if (x % e == 0) return 0;
        if (e * e > x) break;
    }
    return 1;
}

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= MOD;
    if (y % 2 == 1) k *= x, k %= MOD;
    return k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 2; i <= 3*100000; i++) if (prime(i)) PRIME.emplace_back(i);
    int N; ll M;
    cin >> N >> M;
    ll LCM = 1, R = 1, ans = 0, id = 0;
    for (int i = 1; i <= N; i++) {
        ll TT = poww(M % MOD, i);
        if (i == PRIME[id] && PRIME[id] <= M / LCM) LCM *= PRIME[id++];
        else if (i == PRIME[id]) LCM = M+1;
        R *= (M / LCM) % MOD, R %= MOD;
        TT -= R;
        TT %= MOD, TT += MOD, TT %= MOD;
        ans += TT, ans %= MOD;
    }
    cout << ans << '\n';
}

/*
if an array is not ambigous, all element a_i must be divisible by PROD_prime(1, 2, .. i)

we want to find how many k_i such that
    PROD_prime(1, 2, .., i) * k_i <= m
    k_i <= m / PROD_prime(1, 2, .., i)
    so n(k_i) == floor(m / PROD_prime(1, 2, .., i))
*/