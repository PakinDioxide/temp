// PakinDioxide
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // auto file = freopen("p.in", "r", stdin);
    ll n, q;
    cin >> n >> q;
    ll a[n+1], b[n+1];
    vector <pair <ll, ll>> v;
    for (ll i = 1; i <= n; i++) cin >> a[i], v.emplace_back(a[i], i);
    for (ll i = 1; i <= n; i++) cin >> b[i];
    pair <ll, ll> l[n+1], r[n+1];
    stack <tuple <ll, ll, ll>> st;
    for (ll i = 1; i <= n; i++) {
        l[i] = {0, 0};
        ll q = b[i];
        while (!st.empty() && get<0>(st.top()) <= a[i]) q ^= get<2>(st.top()), st.pop();
        if (st.empty()) q = b[i];
        if (!st.empty()) l[i] = {get<1>(st.top()), (b[get<1>(st.top())] ^ q) * abs(get<0>(st.top()) - a[i])};
        if (!st.empty()) st.emplace(a[i], i, q);
        else st.emplace(a[i], i, b[i]);
    }
    while (!st.empty()) st.pop();
    for (ll i = n; i >= 1; i--) {
        r[i] = {0, 0};
        ll q = b[i];
        while (!st.empty() && get<0>(st.top()) <= a[i]) q ^= get<2>(st.top()), st.pop();
        if (st.empty()) q = b[i];
        if (!st.empty()) r[i] = {get<1>(st.top()), (b[get<1>(st.top())] ^ q) * abs(get<0>(st.top()) - a[i])};
        if (!st.empty()) st.emplace(a[i], i, q);
        else st.emplace(a[i], i, b[i]);
    }
    // cout << "L ";
    // for (ll i = 1; i <= n; i++) cout << l[i].first << ' ';
    // cout << '\n' << "R ";
    // for (ll i = 1; i <= n; i++) cout << r[i].first << ' ';
    // cout << '\n';
    sort(v.begin(), v.end());
    ll dp[n+1][35];
    for (ll i = 1; i <= n; i++) for (ll j = 0; j <= 30; j++) dp[i][j] = LLONG_MAX;
    for (ll i = 0; i <= 30; i++) dp[v[n-1].second][i] = 0;
    for (ll i = n-1; i >= 1; i--) {
        ll idx = v[i-1].second;
        // cout << l[idx].first << ' ' << r[idx].first << '\n';
        if (l[idx].first == 0 || r[idx].first == 0) {
            ll p, q;
            if (l[idx].first == 0) p = r[idx].first, q = r[idx].second;
            else p = l[idx].first, q = l[idx].second;
            // cout << idx << ' ' << p << ' ' << dp[p][0] << ' ';
            for (ll j = 0; j <= 30; j++) {
                if (dp[p][j] == LLONG_MAX) {if (j > 0) dp[idx][j] = dp[idx][j-1];}
                else dp[idx][j] = dp[p][j] + q;
            }
        } else {
            if (a[l[idx].first] > a[r[idx].first]) {
                for (ll j = 0; j <= 30; j++) {
                    if (dp[r[idx].first][j] == LLONG_MAX) {if (j > 0) dp[idx][j] = min(dp[idx][j], dp[idx][j-1]);}
                    else dp[idx][j] = min(dp[idx][j], dp[r[idx].first][j] + r[idx].second);
                }
                for (ll j = 1; j <= 30; j++) {
                    if (dp[l[idx].first][j-1] == LLONG_MAX) {if (j > 0) dp[idx][j] = min(dp[idx][j], dp[idx][j-1]);}
                    else dp[idx][j] = min(dp[idx][j], dp[l[idx].first][j-1] + l[idx].second);
                }
            } else {
                for (ll j = 0; j <= 30; j++) {
                    if (dp[l[idx].first][j] == LLONG_MAX) {if (j > 0) dp[idx][j] = min(dp[idx][j], dp[idx][j-1]);}
                    else dp[idx][j] = min(dp[idx][j], dp[l[idx].first][j] + l[idx].second);
                }
                for (ll j = 1; j <= 30; j++) {
                    if (dp[r[idx].first][j-1] == LLONG_MAX) {if (j > 0) dp[idx][j] = min(dp[idx][j], dp[idx][j-1]);}
                    else dp[idx][j] = min(dp[idx][j], dp[r[idx].first][j-1] + r[idx].second);
                }
            }
        }
        for (ll j = 1; j <= 30; j++) dp[idx][j] = min(dp[idx][j], dp[idx][j-1]);
        // cout << idx << ' ' << dp[idx][0] << '\n';
    }

    while (q--) {
        ll x, y, k;
        cin >> x >> y >> k;
        ll p = 0, q = 0, ans = dp[x][0] + dp[y][0];
        for (ll i = k; i >= 0; i--) {
            for (ll j = 0; j <= k-i; j++) {
                if (dp[x][i] + dp[y][j] < ans) ans = dp[x][i] + dp[y][j], p = i, q = j;
                else if (dp[x][i] + dp[y][j] == ans && i+j < p+q) ans = dp[x][i] + dp[y][j], p = i, q = j;
                else if (dp[x][i] + dp[y][j] == ans && i+j == p+q && i > p) ans = dp[x][i] + dp[y][j], p = i, q = j;
            }
        }
        // for (ll i = 0; i <= k; i++) {
        //     if (dp[x][i] + dp[y][k-i] <= ans) p = i, q = k-i, ans = dp[x][i] + dp[y][k-i];
        // }
        cout << p << ' ' << q << '\n' << ans << '\n';
        // cout << dp[x][0] << ' ' << dp[y][0] << '\n';
    }
}