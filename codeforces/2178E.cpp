#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ask(int l, int r) { cout << "? " << l << ' ' << r << endl; ll x; cin >> x; return x; }

int find(int l, int r, ll s) {
    int L = l;
    while (l < r) {
        int x = l + (r-l)/2;
        ll y = 2*ask(L, x);
        if (y == s) return x;
        else if (y < s) l = x+1;
        else r = x-1;
    }
    return l;
}

ll solve() {
    int n; cin >> n;
    ll s = ask(1, n);
    if (n == 1) return s;
    int m = find(1, n, s);
    s /= 2;
    int l = 1, r = n;
    while (l < r) {
        // cout << l << ' ' << r << ' ' << m << '\n';
        if (m-l == 0 || r-m == 1) return s;
        int m1 = find(l, m, s), m2 = find(m+1, r, s);
        if (min(m1-l, m-m1) <= min(m2-(m+1), r-m2)) r = m, m = m1;
        else l = m+1, m = m2;
        s /= 2;
    }
    return s;
    ll ans = 0;
    ll k = 1e5;
    for (int i = 0; (1 << i) <= k; i++) ans += ceil(log2(k/(1<<i)));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int k = solve();
        cout << "! " << k << endl;
    }
}

/*
O(log^2(N))?
O(sqrt(N))????

A, B is bruh

A can come with out B

no need consider concat

S = 2^st

n - 1 = number of divide
*/
