/*
    author  : PakinDioxide
    created : 15/03/2025 01:30
    task    : 782B
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll x[n], v[n];
    for (auto &e : x) cin >> e;
    for (auto &e : v) cin >> e;;
    auto calc = [&] (double idx) {
        double t = 0;
        for (int i = 0; i < n; i++) t = max(t, (double) abs(idx-x[i])/v[i]);
        return t;
    };
    double l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        double m1 = (l+r)/2, m2 = (l+r)/2+1e-7;
        if ((r-l) < 1e-7) {ans = calc(l); break;}
        double p = calc(m1), q = calc(m2);
        if ((m1-l) < 1e-7 && (r-m2) < 1e-7) {ans = min(p, q); break;}
        if (p > q) l = m1+1e-7;
        else if (p < q) r = m2-1e-7;
        else l = m1+1e-7, r = m2-1e-7;
    }
    cout << setprecision(7) << ans << '\n';
}