/*
    author  : PakinDioxide
    created : 28/03/2025 20:10
    task    : JOI22_ho_t2
*/
#include <bits/stdc++.h>
#define ll unsigned long long
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n; ld m;
    cin >> n >> m;
    ld a[n], b[n];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    ld l = 0, r = ULLONG_MAX, ans = 0;
    while (l <= r) {
        ll x = floor(l + (r-l)/2), cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= b[i]) {
                if (a[i] * m >= x) cnt += ceil((ld) x / a[i]);
                else cnt += m + ceil((ld) (x - a[i] * m) / b[i]);
            } else cnt += ceil((ld) x / b[i]);
            if (cnt > n*m) break;
        }
        if (cnt <= n*m) ans = x, l = x+1;
        else r = x-1;
    }
    cout << (ll) ans << '\n';
}