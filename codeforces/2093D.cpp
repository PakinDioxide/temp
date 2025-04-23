/*
    author  : PakinDioxide
    created : 08/04/2025 21:53
    task    : 2093D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <ll, ll> qr2(ll n, ll k) {
    if (n == 0) return make_pair(1, 1);
    if (k <= (1LL << (2*n-2))) {
        pair <ll, ll> p = qr2(n-1, k);
        return p;
    } else if (k <= (1LL << (2*n-1))) {
        pair <ll, ll> p = qr2(n-1, k - (1LL << (2*n-2)));
        p.first += (1LL << (n-1)), p.second += (1LL << (n-1));
        return p;
    } else if (k <= ((1LL << (2*n-1)) + (1LL << (2*n-2)))) {
        pair <ll, ll> p = qr2(n-1, k - (1LL << (2*n-1)));
        p.first += (1LL << (n-1));
        return p;
    } else {
        pair <ll, ll> p = qr2(n-1, k - ((1LL << (2*n-1)) + (1LL << (2*n-2))));
        p.second += (1LL << (n-1));
        return p;
    }
}

ll qr1(ll n, ll x, ll y) {
    if (n == 0) return 1;
    if (x <= (1LL << (n-1)) && y <= (1LL << (n-1))) {
        ll k = qr1(n-1, x, y);
        return k;
    } else if (x > (1LL << (n-1)) && y > (1LL << (n-1))) {
        ll k = qr1(n-1, x - (1LL << (n-1)), y - (1LL << (n-1)));
        k += (1LL << (2*n-2));
        return k;
    } else if (x > (1LL << (n-1)) && y <= (1LL << (n-1))) {
        ll k = qr1(n-1, x - (1LL << (n-1)), y);
        k += (1LL << (2*n-1));
        return k;
    } else {
        ll k = qr1(n-1, x, y - (1LL << (n-1)));
        k += ((1LL << (2*n-1)) + (1LL << (2*n-2)));
        return k;
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "->") {
            ll x, y;
            cin >> x >> y;
            cout << qr1(n, x, y) << '\n';
        } else {
            ll x;
            cin >> x;
            pair <ll, ll> p = qr2(n, x);
            cout << p.first << ' ' << p.second << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}