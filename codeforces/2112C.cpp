/*
    author  : 
    created : 23/06/2025 21:49
    task    : 2112C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    ll a[n], cnt = 0; for (auto &e : a) cin >> e;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n-1; j++) {
        ll xy = a[i] + a[j];
        if (xy > a[n-1]) cnt++;
        int ridx = lower_bound(a+j+1, a+n-1, xy) - a - 1;
        if (ridx <= j) continue;
        int lidx = upper_bound(a+j+1, a+n-1, a[n-1] - xy) - a;
        cnt += max(0, ridx - lidx + 1);
        // cout << i << ' ' << j << ' ' << max(0, ridx - lidx + 1) << '\n';
        // cout << cnt << '\n';
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*

let we color x <= y <= z

x + y must > z

two ways 1. if not color greatest x+y+z must > greatest, and follow the rules
         2. if color the greatest
*/