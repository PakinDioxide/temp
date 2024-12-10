#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[100005];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int l = 0, r = INT_MAX, ans = 0;
    while (l <= r) {
        int mid = l + (r - l)/2, cnt = 0, s = 0;
        priority_queue <int> q;
        for (int i = 0; i < n; i++) {
            s += a[i];
            q.emplace(-a[i]);
            if (q.size() > k) {
                s += q.top();
                q.pop();
            }
            if (s >= mid && q.size() == k) {
                cnt++;
                s = 0;
                while (!q.empty()) q.pop();
            }
        }
        if (cnt >= m) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d", ans);
}