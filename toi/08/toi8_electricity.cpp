#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    deque <pair <int, int>> dq;
    dq.emplace_back(0, a[0]);
    for (int i = 1; i < n; i++) {
        while (!dq.empty() && i - dq.front().first > k) dq.pop_front();
        int e = dq.front().second + a[i];
        while (!dq.empty() && dq.back().second > e) dq.pop_back();
        dq.emplace_back(i, e);
    }
    cout << dq.back().second;
}