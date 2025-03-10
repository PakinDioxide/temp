#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (auto i : s) cnt += (i == '1');
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}