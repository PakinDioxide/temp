#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int cnt = 0, ans = 0;
    while (n--) {
        string s;
        cin >> s;
        cnt += s.size();
        if (cnt <= m) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}