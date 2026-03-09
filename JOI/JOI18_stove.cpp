#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int main() {
    int n, k; cin >> n >> k;
    ll a[n]; for (auto &e : a) cin >> e;
    sort(a, a+n);
    vector <ll> v;
    for (int i = 0; i < n-1; i++) v.emplace_back(a[i+1] - a[i] - 1);
    sort(v.begin(), v.end());
    ll ans = a[n-1] - a[0] + 1;
    while (--k && v.size() && v.back() > 0) ans -= v.back(), v.pop_back();
    cout << ans << '\n';
}
