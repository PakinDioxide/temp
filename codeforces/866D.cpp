#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    priority_queue <ll> q;
    ll ans = 0;
    while (n--) {
        ll x; cin >> x;
        ans -= x;
        q.emplace(-x);
        q.emplace(-x);
        q.pop();
    }
    while (!q.empty()) ans -= q.top(), q.pop();
    cout << ans << '\n';
}

