/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <tuple <ld, ld, ld>> a;
    for (int i = 0; i < n; i++) { ld x, y; cin >> x >> y; a.emplace_back(atan2(y, x), x, y); }
    sort(a.begin(), a.end());
    for (auto &[k, x, y] : a) cout << fixed << setprecision(0) << x << ' ' << y << '\n';
}
