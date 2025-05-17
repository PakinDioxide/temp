/*
    author  : PakinDioxide
    created : 02/05/2025 01:12
    task    : f
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, k;
    cin >> n >> k;
    priority_queue <pair <ll, ll>> q;
    ll ans = LLONG_MAX, sum = 0;
    auto add = [&] (ll x) {
        if (x == 0) return;
        q.emplace(x*x-(x/2)*(x/2)-ceil(x/2.0)*ceil(x/2.0), x);
    };
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        add(x);
        sum += x*x;
    }
    ll kk = k;
    while (!q.empty() && k--) {
        auto [w, x] = q.top(); q.pop();
        sum -= w;
        ans = min(ans, (kk-k)*(kk-k) + sum);
        if (x == 1) continue;
        add(x/2), add(ceil(x/2.0));
    }
    cout << ans << '\n';
}