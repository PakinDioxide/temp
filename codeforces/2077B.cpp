#include <bits/stdc++.h>
#define ll long long

using namespace std;

int ask(int x) { cout << x << endl; int k; cin >> k; return k; }

void solve() {
    int x1 = 0, x2 = 0;
    for (int i = 0; i < 30; i++) {
        if (!(i & 1)) x1 |= (1 << i);
        else x2 |= (1 << i);
    }
    int k1 = ask(x1) - 2*x1, k2 = ask(x2) - 2*x2;
    int cnt[31]; memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 31; i++) {
        if ((i & 1)) {
            if (k1 & (1 << i)) cnt[i] = 1;
        } else {
            if (k1 & (1 << i)) cnt[i-1] = 2;
        }
    }
    for (int i = 0; i < 31; i++) {
        if (!(i & 1)) {
            if (k2 & (1 << i)) cnt[i] = 1;
        } else {
            if (k2 & (1 << i)) cnt[i-1] = 2;
        }
    }
    int ans = 0, k;
    cout << "!" << endl; cin >> k;
    for (int i = 0; i < 30; i++) {
        if (k & (1 << i)) ans += 2 * (1 << i);
        else ans += cnt[i] * (1 << i);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

