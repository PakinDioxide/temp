/*
    author  : PakinDioxide
    created : 19/04/2025 21:35
    task    : 2096A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    deque <int> dq;
    string s;
    cin >> s;
    dq.emplace_back(1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') dq.emplace_front(i+2);
        else dq.emplace_back(i+2);
    }
    int ans[n+1], cnt = 0;
    for (auto &e : dq) ans[e] = ++cnt;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}