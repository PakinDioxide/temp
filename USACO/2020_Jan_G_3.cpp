/*
    author  : PakinDioxide
    created : 31/03/2025 15:16
    task    : 2020_Jan_G_3
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fen[200005];

void add(int idx, ll x) {
    for (int i = idx; i < 200005; i += i & (-i)) fen[i] = min(fen[i], x);
}

ll qr(int idx) {
    ll x = LLONG_MAX;
    for (int i = idx; i > 0; i -= i & (-i)) x = min(x, fen[i]);
    return x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <tuple <ll, ll, int, int>> v; // y, x type, idx
    vector <tuple <ll, ll, ll, ll>> a(k);
    vector <ll> cmp;
    ll dis[k];
    for (int i = 0; i < 200005; i++) fen[i] = LLONG_MAX;
    for (int i = 0; i < k; i++) dis[i] = LLONG_MAX;
    add(1, 2*n);
    cmp.emplace_back(1);
    cmp.emplace_back(n+1);
    for (int i = 0; i < k; i++) {
        auto &[x1, y1, x2, y2] = a[i];
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = n-x1, y1 = n-y1, x2 = n-x2, y2 = n-y2;
        x1++, x2++, y1++, y2++;
        cmp.emplace_back(x1);
        cmp.emplace_back(x2);
        if (x1 == x2 && y1 == y2) continue;
        v.emplace_back(y1, x1, 0, i);
        v.emplace_back(y2, x2, 1, i);
    }
    sort(cmp.begin(), cmp.end());
    sort(v.begin(), v.end());
    for (auto [y, x, t, idx] : v) {
        ll cx = upper_bound(cmp.begin(), cmp.end(), x) - cmp.begin();
        ll mn = qr(cx) - (n-x+1) - (n-y+1);
        dis[idx] = min(dis[idx], mn);
        if (t == 0) add(cx, dis[idx] + (n-x+1) + (n-y+1));
    }
    cout << qr(upper_bound(cmp.begin(), cmp.end(), n+1) - cmp.begin()) << '\n';
}

/*
we check the minimum at the end then we set the value to the start?
we sweepline from ymax to 0

we range query but when we add the value to each x we have to plus the distance y and x
then when we find min, we got the min we have to minus from the x y at the end

we can use BIT to do since each query will ask (l, max n)

we should invert the idx first

when we sweep line from the end
    if we encounter the start, we will add the value to x + we will query the distance too
    else we will query the minimum distance
*/