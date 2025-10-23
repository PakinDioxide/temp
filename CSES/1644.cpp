/*
    author  : PakinDioxide
    created : 25/03/2025 22:36
    task    : 1644
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    ll a[n+1], p[n+1];
    p[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = a[i] + p[i-1];
    }
    multiset <ll> ms;
    ll mx = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        if (i > y) ms.erase(ms.find(p[i-y-1]));
        if (i >= x) ms.insert(p[i-x]);
        if (i >= x) mx = max(mx, p[i] - *ms.begin());
    }
    cout << mx << '\n';
}