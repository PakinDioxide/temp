#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 3e5+5;

ll fen[mxN], n;

void upd(int idx, ll x) { for (int i = idx; i <= n; i += i & -i) fen[i] = max(fen[i], x); }
ll qr(int idx) { ll x = LLONG_MIN; for (int i = idx; i > 0; i -= i & -i) x = max(x, fen[i]); return x; }

int main() {
    ll d; cin >> n >> d;
    for (int i = 1; i <= n; i++) fen[i] = LLONG_MIN;
    ll a[n+1], p[n+1]; p[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll b[n+1], A[n+1];
    for (int i = 1; i <= n; i++) A[i] = a[i];
    b[n] = a[n]/d;
    ll idk = 0, D = d;
    for (int i = n-1; i > 0; i--) {
        b[i] = a[i]/d;
        if (a[i] % d > a[i+1] % d) idk++;
        b[i] += idk;
    }
    for (int i = 1; i <= n; i++) a[i] = b[i];//, cout << a[i] << ' '; cout << '\n';
    for (int i = 1; i <= n; i++) p[i] = p[i-1] + a[i];
    d = 1;
    int q; cin >> q;
    vector <tuple <int, int, int>> Q(q);
    int it = 0;
    ll ans[q+1];
    for (auto &[y, x, id] : Q) cin >> x >> y, id = ++it;
    sort(Q.begin(), Q.end());
    reverse(Q.begin(), Q.end());
    ll dp[n+1]; dp[0] = 0;
    vector <pair <int, ll>> v; v.emplace_back(0, LLONG_MIN);
    for (int i = 1; i <= n; i++) {
        upd(n-i+1, a[i] - A[i]/D);
        while (v.size() && v.back().second > a[i]) v.pop_back();
        dp[i] = dp[v.back().first] + p[i] - p[v.back().first] - (i - v.back().first) * a[i];
        v.emplace_back(i, a[i]);
        // cout << "# " << i << '\n';
        // for (auto &[x, y] : v) cout << x << ' ' << y << ' ' << dp[x] << '\n';
        while (Q.size() && get<0>(Q.back()) == i) {
            auto &[y, x, id] = Q.back(); Q.pop_back();
            pair <int, ll> it = (*lower_bound(v.begin(), v.end(), make_pair(x, LLONG_MIN)));
            ans[id] = dp[i] - dp[it.first] + (p[it.first] - p[x-1]) - (it.first - x + 1) * a[it.first];
            // cout << id << ' ' << a[it.first] << ' ' << qr(n-x+1) << '\n';
            if (a[it.first] < qr(n-x+1)) ans[id] = -1;
        }
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
