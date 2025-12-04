/*
    author  : PakinDioxide
    created : 26/05/2025 19:47
    task    : IOI07_sails
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n;
pair <ll, ll> a[mxN];
ll fen[mxN], idx = LLONG_MAX, ans = 0, t;

void upd(int idx, ll x) { for (int i = idx; i <= mxN; i += i & -i) fen[i] += x; }
void rg(int l, int r, ll x) { upd(r+1, -x), upd(l, x); }
ll qr(int idx) { ll x = 0; for (int i = idx; i > 0; i -= i & -i) x += fen[i]; return x; }
int get(ll x) {
    int l = 1, r = mxN-1, ans = 0;
    while (l <= r) {
        int mid = l + (r-l)/2;
        if (qr(mid) >= x) ans = mid, l = mid+1;
        else r = mid-1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) {
        auto &[h, c] = a[i];
        int l = h-c+1, r = h;
        // cout << l << ' ' << r << '\n';
        int l_ = get(qr(l)+1) + 1, r_ = get(qr(l));
        // cout << l << ' ' << r << ' ' << l_ << ' ' << r_ << '\n';
        if (r_-l+1 >= c) rg(l_, l_+c-1, 1), c = 0;
        else rg(l_, l_+(r_-l+1)-1, 1), c -= (r_-l+1);
        rg(r-c+1, r, 1);
        // cout << h << ' ' << c << '\n';
        // for (int i = 1; i <= 5; i++) cout << qr(i) << ' ';
        // cout << '\n';
    }
    for (int i = 1; i < mxN; i++) t = qr(i), ans += t*(t-1)/2;
    cout << ans << '\n';
}

/*
if there are n sails on each hight, the inefficiency will be n*(n-1)/2
*/