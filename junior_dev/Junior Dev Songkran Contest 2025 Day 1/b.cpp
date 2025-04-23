/*
    author  : PakinDioxide
    created : 13/04/2025 18:01
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mxN = 5e5+5;
ll n, a1, d;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> n >> a1 >> d >> t;
    ll L = a1, R = a1 + (n-1)*d;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        if (d == 0) {
            if (l <= a1 && r >= a1) cout << a1*n << '\n';
            else cout << 0 << '\n';
            continue;
        }
        if (r < L || l > r) {cout << 0 << '\n'; continue;}
        l = max(l, L);
        r = min(r, R);
        l += (d-((l-a1+d)%d))%d;
        r -= (r-a1+d)%d;
        ll cnt = (r-l)/d+1;
        cout << cnt*(l+r)/2 << '\n';
    }
}