#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector <int> cnt(k), cc(k), val(n);
    for (int i = 0; i < (n-k+1) - 1; i++) {
        if (s[i] != s[i+1]) val[i+k] = !val[i];
        else val[i+k] = val[i];
    }
    for (int i = 0; i < n; i++) cnt[i % k] += val[i], cc[i % k]++;
    int S = 0;
    for (int i = 0; i < k; i++) S += cnt[i];
    int A = S, B = S;
    vector <int> swp;
    for (int i = 0; i < k; i++) swp.emplace_back((cc[i] - cnt[i]) - cnt[i]);
    sort(swp.begin(), swp.end());
    // find min
    int ADD = 0;
    if (s[0] == '1') A += swp[0], B += swp[k-1], ADD = 1;
    for (int i = ADD; i+1 < k && swp[i] + swp[i+1] < 0; A += swp[i] + swp[i+1], i += 2);
    for (int i = k - 1 - ADD; i > 0 && swp[i] + swp[i-1] > 0; B += swp[i] + swp[i-1], i -= 2);
    cout << A << ' ' << B << '\n';
    assert(A <= n && B <= n);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
