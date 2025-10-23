/*
    author  : PakinDioxide
    created : 20/08/2025 22:08
    task    : 1094
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5, mxK = 55;
const ll mod = 1e9+7;

int n, k, a[mxN];
ll dp[mxK][mxN];
vector <int> cmp;

void upd(int idx, ll x, int k) { for (int i = idx; i < mxN; i += i & -i) dp[k][i] += x, dp[k][i] %= mod; }
ll qr(int idx, int k) { ll s = 0; for (int i = idx; i > 0; i -= i & -i) s += dp[k][i], s %= mod; return s; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], cmp.emplace_back(a[i]); cmp.emplace_back(0);
    sort(cmp.begin(), cmp.end());
    upd(1, 1, 0);
    for (int i = 0; i < n; i++) {
        a[i] = upper_bound(cmp.begin(), cmp.end(), a[i]) - cmp.begin();
        for (int j = k; j >= 1; j--) upd(a[i], qr(a[i]-1, j-1), j);
    }
    cout << qr(n+1, k) << '\n';
}