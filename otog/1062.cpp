/*
    author  : PakinDioxide
    created : 01/05/2025 00:53
    task    : 1062
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, l, r;
    cin >> n >> l >> r;
    ll p[n+1], a[n+1];
    p[0] = a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
    int idx = 0; ll mx = 0;
    deque <pair <ll, ll>> dq;
    for (int i = 1; i <= n; i++) {
        while (idx < n && p[i] - p[idx+1] + 1 >= l) {
            while (!dq.empty() && dq.back().first >= a[idx]) dq.pop_back();
            dq.emplace_back(a[idx], idx);
            idx++;
        }
        while (!dq.empty() && p[i] - p[dq.front().second + 1] + 1 > r) dq.pop_front();
        if (!dq.empty()) mx = max(mx, a[i] - dq.front().first);
        else mx = max(mx, a[i] - a[i-1]);
    }
    for (int i = 1; i <= n && p[i] - p[1] + 1 <= r; i++) mx = max(mx, a[i]);
    for (int i = n; i > 0 && p[n] - p[i] + 1 <= r; i--) mx = max(mx, a[n] - a[i-1]);
    cout << mx << '\n';
}