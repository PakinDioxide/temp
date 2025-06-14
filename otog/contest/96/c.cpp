/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

#pragma GCC optimize("O2")
#pragma GCC target("avx2")

struct T {
    int x1, y1, x2, y2;
};

int ar(T a) {
    return (a.x2-a.x1+1)*(a.y2-a.y1+1);
}

int goToSpace(int n, int m, int k, vector <pair <int, int>> v) {
    vector <vector <int>> p(n+1, vector <int>(m+1));
    for (auto &[x, y] : v) p[x][y]++;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) p[i][j] += p[i-1][j] + p[i][j-1] - p[i-1][j-1];
    auto calc = [&] (int x1, int y1, int x2, int y2) {
        return p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1];
    };
    vector <int> dpx(n+1, INT_MAX), dprx(n+1, INT_MAX), dpy(m+1, INT_MAX), dpry(m+1, INT_MAX);
    for (int x1 = 1; x1 <= n; x1++) for (int x2 = x1; x2 <= n; x2++) if (calc(x1, 1, x2, m)) {
        int y1 = 1, cnt = 0;
        for (int y2 = 1; y2 <= m; y2++) {
            cnt += calc(x1, y2, x2, y2);
            while (cnt > k) {
                cnt -= calc(x1, y1, x2, y1); y1++;
            }
            while (cnt == k) {
                int k = ar(T{x1, y1, x2, y2});
                dpx[x2] = min(dpx[x2], k);
                dprx[x1] = min(dprx[x1], k);
                dpy[y2] = min(dpy[y2], k);
                dpry[y1] = min(dpry[y1], k);
                cnt -= calc(x1, y1, x2, y1); y1++;
            }
        }
    }
    for (int i = 2; i <= n; i++) dpx[i] = min(dpx[i], dpx[i-1]);
    for (int i = 2; i <= m; i++) dpy[i] = min(dpy[i], dpy[i-1]);
    for (int i = n-1; i >= 1; i--) dprx[i] = min(dprx[i], dprx[i+1]);
    for (int i = m-1; i >= 1; i--) dpry[i] = min(dpry[i], dpry[i+1]);
    ll mn = INT_MAX;
    for (int Y = 1; Y < m; Y++) {
        ll p = dpy[Y], q = dpry[Y+1];
        mn = min(mn, p+q);
    }
    for (int X = 1; X < n; X++) {
        ll p = dpx[X], q = dprx[X+1];
        mn = min(mn, p+q);
    }
    if (mn < INT_MAX) return mn;
    else return -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, cnt, k;
    cin >> n >> m >> cnt >> k;
    vector <pair <int, int>> q(cnt);
    for (auto &[x, y] : q) cin >> x >> y;
    cout << goToSpace(n, m, k, q) << '\n';
}
