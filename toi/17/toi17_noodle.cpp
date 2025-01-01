#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    ll a[n], l = 0, r = 0, ans = LLONG_MAX;
    for (int i = 0; i < n; i++) cin >> a[i], r += a[i];
    priority_queue <ll> q;
    while (l <= r) {
        ll mid = (l+r)/2, cnt = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (q.size() < k) sum += a[i], q.push(-a[i]);
            else if (-q.top() < a[i]) sum += q.top() + a[i], q.pop(), q.push(-a[i]);
            if (sum >= mid && q.size() == k) {
                sum = 0, cnt++;
                while (!q.empty()) q.pop();
            }
            if (cnt == m) break;
        }
        while (!q.empty()) q.pop();
        if (cnt >= m) l = mid+1, ans = mid;
        else r = mid-1;
    }
    cout << ans;
}