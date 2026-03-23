#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    pair <ll, int> a[n+1];
    ll P[n+1]; memset(P, 0, sizeof(P));
    for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) P[i] = P[i-1] + a[i].first;
    ll p, q; cin >> p >> q;
    ll L = 0, R = n-1, ans = n-1;
    while (L <= R) {
        ll x = L + (R-L)/2;
        int ok = 0;
        for (int i = 0; i <= x; i++) {
            int j = x-i;
            ll AVG_T = P[n-j] - P[i], AVG_D = n-x;
            ll MX = a[n-j].first;
            // MX / (AVG_T / AVG_D) <= P/Q
            // MX * AVG_D * Q <= P * AVG_T
            if (MX * AVG_D * q <= p * AVG_T) { ok = 1; break; }
        }
        if (ok) ans = x, R = x-1;
        else L = x+1;
    }
    int mn = INT_MAX, mx = 0;
    int cnt[n+2]; memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i <= ans; i++) {
        int j = ans-i;
        ll AVG_T = P[n-j] - P[i], AVG_D = n-ans;
        ll MX = a[n-j].first;
        if (MX * AVG_D * q <= p * AVG_T) {
            int l = 0, r = i+1, ans2 = i+1;
            while (l <= r) {
                int x = l + (r-l)/2;
                ll AVG_t = AVG_T - a[i+1].first + a[x].first;
                if (MX * AVG_D * q <= p * AVG_t) ans2 = x, r = x-1;
                else l = x+1;
            }
            cnt[ans2]++;
            cnt[n-j+1]--;
        }
    }
    map <ll, int> sf;
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i-1];
    for (int i = 1; i <= n; i++) if (cnt[i]) sf[a[i].first] = 1;
    vector <int> v;
    for (int i = 1; i <= n; i++) if (!cnt[i] && !sf[a[i].first]) v.emplace_back(a[i].second);
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto &e : v) cout << e << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

