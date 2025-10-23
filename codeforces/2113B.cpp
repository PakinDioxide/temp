/*
    author  : 
    created : 15/06/2025 16:12
    task    : 2113B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll w, h, a, b; cin >> w >> h >> a >> b;
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if ((((abs(x1-x2)-a)%a == 0 && (abs(y1-y2)-b)%b == 0))) cout << "Yes\n";
    else if ((abs(x1-x2)-a)%a == 0 && x1 != x2) cout << "Yes\n";
    else if ((abs(y1-y2)-b)%b == 0 && y1 != y2) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}