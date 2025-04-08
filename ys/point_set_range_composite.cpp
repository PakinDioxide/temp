/*
    author  : PakinDioxide
    created : 30/03/2025 21:18
    task    : point_set_range_composite
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair <ll, ll> seg[2000000], A[500005];
ll mod = 998244353;

void upd(int l, int r, pair <ll, ll> x, int idx, int node) {
    if (l == r) seg[node] = x;
    else {
        int mid = l + (r-l)/2;
        if (mid >= idx) upd(l, mid, x, idx, node*2+1);
        else upd(mid+1, r, x, idx, node*2+2);
        auto [a1, b1] = seg[node*2+1];
        auto [a2, b2] = seg[node*2+2];
        seg[node] = make_pair((a2*a1) % mod, (a2*b1 + b2) % mod);
    }
}

pair <ll, ll> sum(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = l + (r-l)/2;
        pair <ll, ll> ans;
        int ok = 0;
        if (mid >= x) {
            ans = sum(l, mid, x, y, node*2+1);
            ok = 1;
        }
        if (mid+1 <= y) {
            if (!ok) ans = sum(mid+1, r, x, y, node*2+2);
            else {
                auto [a1, b1] = ans;
                auto [a2, b2] = sum(mid+1, r, x, y, node*2+2);
                ans = make_pair((a2*a1) % mod, (a2*b1 + b2) % mod);
            }
        }
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> A[i].first >> A[i].second;
        upd(1, n, A[i], i, 0);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int idx; ll a, b;
            cin >> idx >> a >> b;
            idx++;
            upd(1, n, make_pair(a, b), idx, 0);
        } else {
            int l, r; ll x;
            cin >> l >> r >> x;
            l++;
            auto [a, b] = sum(1, n, l, r, 0);
            cout << (a*x + b) % mod << '\n';
        }
    }
}

/*
ax+b
c(ax+b) + d
acx + cb + d
e(acx+cb+d) + f
acex + e(cb+d) + f
acex + ceb + ed + f

e(cx + d) + f
ecx + ed+f

ec(ax+b) + d+f
acex + ceb + ed + f
*/