#include <bits/stdc++.h>
#define ll long long

using namespace std;

void prin(ll n) {
    for (int i = 6; i >= 0; i--) cout << ((n & (1 << i)) > 0);
    cout << '\n';
}

void solve() {
    ll n, k; cin >> n >> k;
    if (k % 2 == 1) {
        while (k--) cout << n << ' '; cout << '\n';
        return;
    }
    ll mx = 0, iiii = 0;
    for (int i = 0; i <= n; i++) if ((n ^ i) <= n) {
        if (i*(k-1) + (n^i) >= mx) {
            iiii = i;
            mx = i*(k-1) + (n ^ i);
        }
    }
    // TEST
    for (int i = 1; i < k; i++) cout << iiii << ' ';
    cout << (n^iiii) << '\n';
    return;
    cout << "REAL : " << mx << ' ' << iiii << '\n';
    prin(n);
    prin(iiii);
        vector <int> v;
    for (int i = 30; i >= 0; i--) if (n & (1 << i)) v.emplace_back(i);
    if (v.size() == 1) {
        cout << 0 << ' '; k--;
        while (k--) cout << n << ' '; cout << '\n';
        return;
    }
    ll kk = n;
    int idx = v.back();
    kk ^= (1 << idx);
    for (int i = idx-1; i >= 0; i--) kk |= (1 << i);
    prin(kk);
    ll summ = 0;
    if (kk * (k-1) + (n^kk) < n*(k-1)) {
        cout << 0 << ' '; k--;
        while (k--) cout << n << ' '; cout << '\n';
        return;
    }
    for (int i = 0; i < k-1; i++) cout << kk << ' ', summ += kk;
    cout << (n^kk) << '\n', summ += (n ^ kk);
    cout << summ << '\n';
    assert(summ == mx);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

