// SUB 3
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 998244353;

int main() {
    ll n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    ll ans = (n*n)%mod;
    ans *= ans, ans %= mod;
    cout << ans << '\n';
}