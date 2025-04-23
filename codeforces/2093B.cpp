/*
    author  : PakinDioxide
    created : 08/04/2025 21:39
    task    : 2093B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    while (s.back() == '0') cnt++, s.pop_back();
    for (auto &e : s) cnt += (e > '0');
    cout << cnt-1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
remove zeroes
*/