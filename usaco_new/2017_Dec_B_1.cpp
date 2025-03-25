/*
    author  : PakinDioxide
    created : 14/03/2025 03:55
    task    : 2017_Dec_B_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    vector <tuple <int, int, int, int>> v;
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v.emplace_back(x1, y1, x2, y2);
    }
    int xx1, yy1, xx2, yy2;
    cin >> xx1 >> yy1 >> xx2 >> yy2;
    for (auto [x1, y1, x2, y2] : v) {
        ans += (x2-x1)*(y2-y1) - max(0, (min(x2, xx2) - max(x1, xx1))) * max(0, (min(y2, yy2) - max(y1, yy1)));
    }
    cout << ans << '\n';
}