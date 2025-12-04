#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll seg[4*mxN];

void upd(int l, int r, int x, ll k, int u) {
    if (l == r) seg[u] += k;
    else {
        int m = l + (r-l)/2;
        if (m >= x) upd(l, m, x, k, u<<1);
        else upd(m+1, r, x, k, u<<1|1);
    }
}




int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);
    int n, k; cin >> n >> k;
    vector <tuple <int, int, ll>> v(n);
}