#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll c[n+1], b[n+1];
    c[0] = b[0] = 0;
    vector <pair <ll, ll>> a;
    a.emplace_back(0, 0);
    for (int i = 1; i <= n; i++) cin >> c[i], c[i] += c[i-1];
    for (int i = 1; i <= n; i++) cin >> b[i], b[i] += b[i-1], a.emplace_back(c[i], b[i]);
    sort(a.begin(), a.end());
    ll ans = LLONG_MAX, kk = 0;
    multiset <pair <ll, ll>> d;
    for (auto [x, y] : a) {
        ll k = ceil(sqrt((double) ans));
        while (x - a[kk].first > k) d.erase(d.find({a[kk].second, a[kk].first})), kk++;
        auto u = lower_bound(d.begin(), d.end(), make_pair(y-k, x)), v = upper_bound(d.begin(), d.end(), make_pair(y+k, x));
        for (auto idx = u; idx != v; idx++) {
            ans = min(ans, (y - (*idx).first)*(y - (*idx).first) + (x - (*idx).second)*(x - (*idx).second));
        }
        d.emplace(y, x);
    }
    cout << ans;
}