#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; ll k; cin >> n >> k;
    ll shf = 0, ans = 0;
    multiset <ll> L, R;
    while (n--) {
        ll x; cin >> x;
        if (L.size() && *prev(L.end()) - shf > x) {
            L.emplace(x+shf);
            L.emplace(x+shf);
            ans += *prev(L.end()) - shf - x;
            auto it = prev(L.end());
            ll y = *it;
            L.erase(it);
            y -= 2*shf;
            R.emplace(y);
        } else if (R.size() && *R.begin() + shf < x) {
            R.emplace(x-shf);
            R.emplace(x-shf);
            ans += x - (*R.begin() + shf);
            auto it = R.begin();
            ll y = *it;
            R.erase(it);
            y += 2*shf;
            L.emplace(y);
        } else {
            L.emplace(x+shf);
            R.emplace(x-shf);
        }
        shf += k;
    }
    cout << ans << '\n';
}

