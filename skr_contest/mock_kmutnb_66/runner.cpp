/*
    author  : PakinDioxide
    created : 25/03/2025 21:32
    task    : runner
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    map <int, string> mp;
    map <int, int> mp2;
    for (int i = 0; i < m; i++) {
        int x;
        string y;
        cin >> x >> y;
        mp[x] = y;
        mp2[x] = i;
    }
    vector <tuple <int, int, string>> v;
    for (int i = 0; i < n; i++) {
        string a, c;
        int b, d;
        cin >> a >> b >> c >> d;
        if (a != mp[b] || c > "07:00") continue;
        v.emplace_back(-d, mp2[b], a);
    }
    sort(v.begin(), v.end());
    if (v.size() < k) cout << -1 << '\n';
    else cout << get<2>(v[k-1]) << '\n';
}