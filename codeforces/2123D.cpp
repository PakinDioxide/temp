/*
    author  : 
    created : 01/07/2025 21:58
    task    : 2123D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0;
    for (auto &e : s) cnt += (e - '0');
    if (cnt <= k || 2*k > n) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
we have to delete that there will always be a segment length with at least 1 one
*/