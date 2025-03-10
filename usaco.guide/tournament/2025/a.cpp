#include <bits/stdc++.h>
#define ll long long

using namespace std;

int cnt[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    int ans = 0, c = 0;
    deque <int> q;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]]) cnt[a[i]]++, q.push_back(a[i]);
        else {
            while (c > 2) {
                cnt[q.front()]--;
                if (cnt[q.front()] == 0) c--;
                q.pop_front();
            }
            q.push_back(a[i]);
            cnt[a[i]]++;
            c++;
        }
        ans = max(ans, (int) q.size());
    }
    cout << ans << '\n';
}