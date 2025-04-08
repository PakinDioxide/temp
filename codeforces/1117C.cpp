/*
    author  : PakinDioxide
    created : 05/04/2025 13:36
    task    : 1117C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

string s;
ll sx, sy, ex, ey, n;
ll dx = 0, dy = 0;

int solve(ll x) {
    ll cnt = x/n;
    ll ddx = dx*cnt, ddy = dy*cnt;
    for (int i = 0; i < x%n; i++) {
        if (s[i] == 'U') ddy++;
        else if (s[i] == 'D') ddy--;
        else if (s[i] == 'L') ddx--;
        else ddx++;
    }
    ll kx = ex-sx, ky = ey-sy;
    return (abs(ddx - kx) + abs(ddy - ky) <= x);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> sx >> sy >> ex >> ey >> n;
    cin >> s;
    for (auto &e : s) {
        if (e == 'U') dy++;
        else if (e == 'D') dy--;
        else if (e == 'L') dx--;
        else dx++;
    }
    ll l = 0, r = 1e18, ans = -1;
    while (l <= r) {
        ll x = l + (r-l)/2;
        if (solve(x)) ans = x, r = x-1;
        else l = x+1;
    }
    cout << ans << '\n';
}