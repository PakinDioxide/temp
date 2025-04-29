/*
    author  : PakinDioxide
    created : 24/04/2025 21:34
    task    : 2106A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (auto &e : s) cnt += (e == '1')*(n-1) + (e == '0');
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}