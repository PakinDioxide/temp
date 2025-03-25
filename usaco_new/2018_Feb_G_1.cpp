/*
    author  : PakinDioxide
    created : 18/03/2025 20:20
    task    : 2018_Feb_G_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    ll a[n], idx = 0;
    for (auto &e : a) cin >> e;
    tuple <ll, ll, int> b[m];
    for (auto &[x, y, id] : b) cin >> x >> y, id = idx++;
    sort(b, b+m);
    ll mn = INT_MAX, ans[m], l = 0, r = m-1;
    for (auto &[x, y, id] : b) { 
        if (y >= mn) {ans[id] = 1; continue;}
        ll cnt = 0, mx = 0;
        for (auto &e : a) cnt = (e > x ? cnt+1 : 0), mx = max(mx, cnt);
        if (mx >= y) ans[id] = 0;
        else ans[id] = 1, mn = min(mn, y);
    }
    for (auto &e : ans) cout << e << '\n';
}
/*
if shoe with x, y pass
shoe with a >= x && b >= y will pass
if shoe with x, y dont pass
shoe with a <= x && b <= y won't pas
*/