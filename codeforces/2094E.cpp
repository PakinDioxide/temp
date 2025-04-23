/*
    author  : PakinDioxide
    created : 13/04/2025 22:55
    task    : 2094E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n], cnt[30], cnt2[30];
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
    for (auto &e : a) {
        cin >> e;
        for (int i = 0; i < 30; i++) cnt[i] += min(1LL, e & (1 << i)), cnt2[i] += !(min(1LL, e & (1 << i)));
    }
    ll mx = 0;
    for (auto &e : a) {
        ll k = 0;
        for (int i = 0; i < 30; i++) {
            if (!(e & (1 << i))) k += (1 << i)*cnt[i];
            else k += (1 << i)*cnt2[i];
        }
        mx = max(mx, k);
    }
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}