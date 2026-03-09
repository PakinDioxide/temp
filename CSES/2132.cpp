#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    ll ans = 0;
    priority_queue <ll> q;
    while (n--) {
        ll x; cin >> x;
        q.emplace(x);
        q.emplace(x);
        if (x < q.top()) ans += q.top() - x;
        q.pop();
    }
    cout << ans << '\n';
}

