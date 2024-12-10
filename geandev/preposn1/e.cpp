#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[100005][26];

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, cnt = 0;
    cin >> n >> k;
    k++;
    deque <pair <int, pair <int, int>>> a;
    a.push_back({0, {0, 0}});
    int r = 0;
    for (int i = 1; i <= n; i++) {
        int x, ok = 0;
        cin >> x;
        a.push_back({i, {a.back().second.first + (x == 0), a.back().second.second + (x == 1)}});
        while (a.size() > 1 && (a.back().second.first - a.front().second.first >= k || a.back().second.second - a.front().second.second >= k)) a.pop_front(), ok = 1;
        if (ok) cnt += (a.front().first - r) * (n - a.back().first + 1)/*, cout << a.front().first << ' ' << a.back().first << '\n'*/;
        r = a.front().first;
    }
    cout << cnt;
}