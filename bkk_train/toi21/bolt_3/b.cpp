/*
    author  : PakinDioxide
    created : 01/05/2025 13:06
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pair <int, int>> v;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) { int x; cin >> x; v.emplace_back(x, i); }
    sort(v.begin(), v.end());
    int mn = INT_MAX, c = 0, idx = 0, l = 0, r = 0;
    vector <int> cnt(n);
    for (auto &e : v) {
        int x, y;
        tie(x, y) = e;
        if (!cnt[y]) c++;
        cnt[y]++;
        while (c == n) {
            if (mn > x - v[idx].first + 1) {
                mn = x - v[idx].first + 1;
                l = v[idx].first, r = x;
            }
            cnt[v[idx].second]--;
            if (!cnt[v[idx].second]) c--;
            idx++;
        }
    }
    cout << l << ' ' << r << '\n';
}

/*
O(nm)
*/