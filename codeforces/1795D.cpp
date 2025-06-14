/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

const ll mod = 998244353;

ll poww(ll x, ll y) {
    if (y == 0) return 1;
    ll k = poww(x, y/2);
    k *= k, k %= mod;
    if (y % 2 == 1) k *= x, k %= mod;
    return k;
}

ll inv(ll x) { return poww(x, mod-2); }

ll ncr(ll x, ll y) {
    ll ans = 1;
    for (int i = 1; i <= x; i++) ans *= i, ans %= mod;
    for (int i = 1; i <= y; i++) ans *= inv(i), ans %= mod;
    for (int i = 1; i <= (x-y); i++) ans *= inv(i), ans %= mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll ans = 1;
    for (int i = 0; i < n/3; i++) {
        ll a[3]; for (auto &e : a) cin >> e;
        sort(a, a+3);
        if (a[0] == a[1] && a[1] == a[2]) ans *= 3;
        else if (a[0] == a[1]) ans *= 2;
        ans %= mod;
    }
    cout << (ans * ncr(n/3, n/6)) % mod << '\n';
}

/*
    let x has 2 red, 1 blue
        y has 1 red, 2 blue
    total red = 2x+y, blue = x+2*y
    we want 2x+y = x+2*y
    then we get x = y
    so we choose n/6 groups for red, n/6 groups for blue
*/
