#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n], b[n];
    for (auto &e : a) cin >> e, e = abs(e), e %= 10;
    for (auto &e : b) cin >> e;
    int can[10];
    memset(can, 0, sizeof(can));
    for (int i = 0; i < n; i++) {
        int ok = 0;
        for (int j = 0; j < 10; j++) if ((a[i]*j)%10 == b[i] && can[j]) ok = 1;
        if (ok || a[i] == b[i]) cout << 'Y';
        else cout << 'N';
        int ncan[10];
        memset(ncan, 0, sizeof(ncan));
        for (int j = 0; j < 10; j++) if (can[j]) ncan[(j*a[i])%10] = 1;
        for (int j = 0; j < 10; j++) can[j] = max(can[j], ncan[j]);
        can[a[i]] = 1;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}