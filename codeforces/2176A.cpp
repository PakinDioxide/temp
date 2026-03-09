#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n]; for (auto &e : a) cin >> e;
    priority_queue <int> q;
    int c = 0;
    for (int i = n-1; i >= 0; i--) {
        while (!q.empty() && -q.top() < a[i]) q.pop(), c++;
        q.emplace(-a[i]);
    }
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}