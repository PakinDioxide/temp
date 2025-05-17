/*
    author  : PakinDioxide
    created : 03/05/2025 21:58
    task    : D1_C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e6+5;

int fen[mxN];

void upd(int x, int y) { for (int i = x; i <= mxN; i += i & -i) fen[i] = max(fen[i], y); }
int qr(int x) { int mx = 0; for (int i = x; i > 0; i -= i & -i) mx = max(mx, fen[i]); return mx; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[2*n];
    vector <int> v;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] = 2*n+1-a[i], a[i+n] = a[i], v.emplace_back(a[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < 2*n; i++) a[i] = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
    int ans = 0, r = 0;
    for (int i = 0; i < 2*n-1; i++) {
        int k = qr(a[i]) + 1;
        ans = max(ans, k);
        if (i > 0) upd(a[i-1], r);
        r = k;
    }
    cout << ans << '\n';
}