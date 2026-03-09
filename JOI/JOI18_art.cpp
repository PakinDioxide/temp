#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <pair <ll, ll>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end());
    ll mn = LLONG_MAX, p = 0, ans = 0;
    for (auto &[sz, x] : a) {
        mn = min(mn, p-sz);
        p += x;
        ans = max(ans, p-sz-mn);
    }
    cout << ans << '\n';
}
