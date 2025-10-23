#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set <int> idxcp;
    map <int, int> cpidx;
    pair <int, int> a[n];
    for (auto &[r, l] : a) cin >> l >> r, idxcp.emplace(l), idxcp.emplace(r);
    // int kkkkk = 0;
    // for (int i : idxcp) cpidx[i] = ++kkkkk;
    // for (auto &[r, l] : a) l = cpidx[l], r = cpidx[r];
    // for (auto [r, l] : a) cout << l << ' ' << r << '\n';
    set <int> us;
    sort(a, a+n);
    int ans = 0;
    for (auto [r, l] : a) {
        for (int i = l; i <= r; i++) {
            auto k = (us.lower_bound(i));
            int ok = 0;
            if (k == us.end() || *k != i) ok = 1;
            if (!ok) continue;
            us.emplace(i);
            ans++;
            break;
        }
    }
    cout << ans << '\n';
}