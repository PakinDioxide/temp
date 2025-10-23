/*
    author  : PakinDioxide
    created : 12/03/2025 18:08
    task    : 1619
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int>> v;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(l, 1);
        v.emplace_back(r+1, -1);
    }
    sort(v.begin(), v.end());
    int ans = 0, sum = 0;
    for (auto [idx, val] : v) sum += val, ans = max(ans, sum);
    cout << ans << '\n';
}