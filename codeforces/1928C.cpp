#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> P;

ll isP(ll x) {
    if (x == 2) return 1;
    for (auto &e : P) if (x % e == 0) return 0;
    return 1;
}

ll cnt(ll x) {
    ll s = 1;
    for (auto &e : P) {
        if (x == 1) break;
        if (x % e != 0) continue;
        ll c = 0;
        while (x % e == 0) c++, x /= e;
        s *= c+1;
    }
    return s;
}

ll solve() {
    ll n, x; cin >> n >> x;
    ll p = n-x, q = n+x+2;
    if (p % 2 == 1 && q % 2 == 1) return 0;
    else if (q % 2 == 1) return cnt(p/2);
    else if (p % 2 == 1) return cnt(q/2);
    else return cnt(p/2) + cnt(q/2) - cnt(__gcd(p, q)/2);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 2; i <= 40000; i++) if (isP(i)) P.emplace_back(i);
    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}

/*
if at the first, 2*k-2 | n-x
else 2*k-2 | n - k - (k-x)
     2*k-2 | n-2*k+x-2+2
     2*k-2 | n+x-2-(2*k-2)
     2*k-2 | n+x-2

8 10
1 2 4 5 8 10
x 2 3 x 5 6

2 6
1 2 3 6
x 2 x 4
*/