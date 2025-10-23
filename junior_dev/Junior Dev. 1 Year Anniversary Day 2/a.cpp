/*
    author  : PakinDioxide
    created : 23/09/2025 18:09
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k; cin >> n >> k; swap(n, k);
    vector <ll> a(n);
    for (auto &e : a) cin >> e;
    sort(a.begin(), a.end());
    ll mn = LLONG_MAX, p = 0, q = 0;
    for (int i = 0; i < n-1; i++) {
        ll x = k-a[i];
        auto it = upper_bound(a.begin()+i+1, a.end(), x);
        if (it != a.end()) {
            if (abs(k - (a[i] + *it)) < mn) p = a[i], q = *it, mn = abs(k - (a[i] + *it));
            else if (abs(k - (a[i] + *it)) == mn && abs(p - q) > abs(a[i] - *it)) p = a[i], q = *it, mn = abs(k - (a[i] + *it));
        }
        if (it != a.begin()+i+1) {
            it = prev(it);
            if (abs(k - (a[i] + *it)) < mn) p = a[i], q = *it, mn = abs(k - (a[i] + *it));
            else if (abs(k - (a[i] + *it)) == mn && abs(p - q) > abs(a[i] - *it)) p = a[i], q = *it, mn = abs(k - (a[i] + *it));
        }
    }
    cout << p + q << '\n' << min(p, q) << ' ' << max(p, q) << '\n';
}