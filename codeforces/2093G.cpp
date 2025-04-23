/*
    author  : PakinDioxide
    created : 08/04/2025 22:36
    task    : 2093G
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (auto &e : a) cin >> e;
    ll l = 0, r = n, ans = -1;
    while (l <= r) {
        ll x = l + (r-l)/2;
        
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
How do we find f(b)??

we know that a + b = 2*(a&b) + a ^ b
a^b = a+b - 2*(a&b)


*/