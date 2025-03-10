#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m], l = 0, r = 0, p = 0, q = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j], r = max(r, a[i][j]);
    while (l <= r) {
        int mid = (l+r)/2, h[m], mx = 0;
        memset(h, 0, sizeof(h));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) h[j] = (a[i][j] >= mid ? h[j]+1 : 0);
            stack <pair <int, int>> st;
            for (int j = 0; j < m; j++) {
                int mn = j;
                while (!st.empty() && st.top().first > h[j]) mx = max(mx, st.top().first * (j-st.top().second)), mn = min(mn, st.top().second), st.pop();
                if (st.empty() || st.top().first < h[j]) st.emplace(h[j], mn);
            }
            while (!st.empty()) mx = max(mx, st.top().first * (m-st.top().second)), st.pop();
            reverse(h, h+m);
            for (int j = 0; j < m; j++) {
                int mn = j;
                while (!st.empty() && st.top().first > h[j]) mx = max(mx, st.top().first * (j-st.top().second)), mn = min(mn, st.top().second), st.pop();
                if (st.empty() || st.top().first < h[j]) st.emplace(h[j], mn);
            }
            while (!st.empty()) mx = max(mx, st.top().first * (m-st.top().second)), st.pop();
            reverse(h, h+m);
        }
        if (mx >= k) l = mid+1, p = mid, q = mx;
        else r = mid-1;
    }
    cout << p << ' ' << q << '\n';
}