/*
    author  : PakinDioxide
    created : 04/05/2025 11:40
    task    : codecube_093
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll ans = n*(n-1)*(n-2)/6, cnt = 0;
    vector <pair <ll, ll>> a(n);
    for (auto &[x, y] : a) cin >> x >> y;
    for (int i = 0; i < n; i++) {
        map <pair <ll, ll>, ll> mp;
        for (int j = 0; j < n; j++) if (i != j) {
            ll x = a[i].first-a[j].first, y = a[i].second-a[j].second;
            ll g = __gcd(x, y);
            x /= g, y /= g;
            mp[{x, y}]++;
        }
        for (auto &[x, y] : mp) if (y >= 2) cnt += y*(y-1)/2;
    }
    cout << ans - cnt/3 << '\n';
}

/*
y = mx + c
y1 = mx1+c
y2 = mx2+c
*/