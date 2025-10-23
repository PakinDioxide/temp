/*
    author  : 
    created : 02/07/2025 22:44
    task    : 1616C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n; int a[n]; for (auto &e : a) cin >> e;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        map <pair <int, int>, int> mp;
        for (int j = i+1; j < n; j++) {
            int g = __gcd(a[i] - a[j], i-j);
            mx = max(mx, ++mp[make_pair((a[i]-a[j])/g, (i-j)/g)]);
        }
    }
    cout << n-1-mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}