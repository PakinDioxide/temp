/*
    author  : PakinDioxide
    created : 25/03/2025 19:31
    task    : sequence
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, a1, d, q;
    cin >> n >> a1 >> d >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (d == 0) {cout << (l <= a1 && a1 <= r ? n*a1 : 0) << '\n'; continue;}
        l -= a1, r -= a1;
        ll idx1 = max(0LL, (long long) ceil((double) l/d)), idx2 = min(n-1, (long long) floor((double) r/d));
        ll x = a1 + idx1 * d, y = a1 + idx2 * d;
        cout << (idx2-idx1+1)*(x+y)/2 << '\n';
    }
}