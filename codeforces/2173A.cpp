#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int c = 0, cc = -1;
    for (auto &e : s) {
        if (e == '1') cc = k;
        else cc--;
        if (cc < 0) c++;
    }
    cout << c << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}