#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n;
    unordered_map <ll, int> cnt;
    ll inf = 0, ans = 0;
    for (int i = 0, x; i < n; i++) cin >> x, cnt[x]++, ans += x;
    cin >> q;
    while (q--) {
        string s; cin >> s;
        if (s[0] == 'I') {
            ll x; cin >> x; inf += x;
        } else {
            ll x, y; cin >> x >> y;
            x -= inf, y -= inf;
            if (x != y) ans -= (x - y) * cnt[x], cnt[y] += cnt[x], cnt[x] = 0;
        }
        cout << ans + n * inf << '\n';
    }
}
