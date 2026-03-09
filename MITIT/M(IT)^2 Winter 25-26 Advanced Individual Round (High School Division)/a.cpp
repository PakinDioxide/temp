#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s; cin >> s;
    vector <pair <int, int>> v;
    v.emplace_back(0, 0);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if ((i == 0 || s[i-1] == 'I') && (s[i] != 'I')) {
            if (s[i] == 'M') v.back().first++;
            else v.back().second++;
        } else {
            if ((s[i-1] != 'I' && s[i] != 'I') || (s[i-1] == 'I' && s[i] == 'I')) v.emplace_back((s[i] == 'M'), (s[i] == 'T'));
        }
    }
    int cnt = 0;
    for (auto &[x, y] : v) cnt += min(x, y/2);
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
/*
MITIT
tim is useless
*/