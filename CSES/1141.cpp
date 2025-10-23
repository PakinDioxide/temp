/*
    author  : PakinDioxide
    created : 12/03/2025 18:04
    task    : 1141
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    map <int, int> dp;
    deque <int> dq;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[a[i]]) {while (dq.front() != a[i]) dp[dq.front()] = 0, dq.pop_front(); dq.pop_front();}
        dp[a[i]] = 1;
        dq.push_back(a[i]);
        ans = max(ans, (int) dq.size());
    }
    cout << ans << '\n';
}