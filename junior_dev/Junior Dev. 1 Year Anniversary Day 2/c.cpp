/*
    author  : PakinDioxide
    created : 23/09/2025 18:09
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> P;

bool is_prime(ll x) {
    for (auto &e : P) {
        if (x % e == 0) return 0;
        if (e*e > x) break;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 2; i <= 4000; i++) if (is_prime(i)) P.emplace_back(i);
    ll v[n+1];
    for (int i = 1; i <= n; i++) {
        if (i == 1 || is_prime(i)) {v[i] = 0; continue;}
        ll x = 0;
        while (i % P[x] != 0) x++;
        v[i] = (P[x] == i ? 0 : i / P[x]);
    }
    ll sf[n+2], pr[n+2];
    memset(sf, 0, sizeof(sf));
    memset(pr, 0, sizeof(pr));
    ll mx = 0;
    for (ll i = 1; i <= n; i++) {
        pr[i] = pr[i-1];
        if (i > mx) mx = max(mx, 2*i-v[i]-1);
        else pr[i] += min(mx, 2*i-v[i]-1)-i+1;
        mx = max(mx, 2*i-v[i]-1);
        // for (int j = i; j < 2*i-v[i]; j++) if (++c[j] >= 2) pr[i]++;
    }
    deque <int> dq;
    for (int i = 2*n; i > n; i--) dq.emplace_front(i);
    for (ll i = n; i > 0; i--) {
        sf[i] = sf[i+1];
        dq.emplace_front(i);
        sf[i] += i-v[i] - (upper_bound(dq.begin(), dq.end(), 2*i-v[i]-1) - dq.begin());
        // cout << i << ' ' << 2*i-v[i]-1 << ' ' << sf[i] << ' ' << (upper_bound(dq.begin(), dq.end(), 2*i-v[i]-1) - dq.begin()) << '\n';
        while (!dq.empty() && dq.front() <= 2*i-v[i]-1) dq.pop_front();
        // if (2*i-v[i]-1 < mx) mx = min(mx, i);
        // else sf[i] += max(i, mx)-(2*i-v[i]-1)+1;
        // mx = min(mx, i);
        // cout << i << ' ' << mx << ' ' << sf[i] << '\n';
        // for (int j = i; j < 2*i-v[i]; j++) if (++c[j] >= 2) sf[i]++;
    }
    while (q--) {
        vector <pair <ll, ll>> a;
        // BRUTEFORCE
        ll c[2*n+1], l, r; cin >> l >> r; // memset(c, 0, sizeof(c));
        if (r == n+1) {
            cout << pr[l-1] << '\n';
            continue;
        } else if (l == 1) {
            cout << sf[r] << '\n';
            continue;
        }
        for (int i = 1; i < l; i++) {
            a.emplace_back(i, 1);
            a.emplace_back(2*i-v[i], -1);
            // for (int j = i; j <= 2*i-1-v[i]; j++) c[j]++;
        }
        for (int i = r; i <= n; i++) {
            a.emplace_back(i, 1);
            a.emplace_back(2*i-v[i], -1);
            // for (int j = i; j <= 2*i-1-v[i]; j++) c[j]++;
        }
        ll cnt = 0, ans = 0;
        // for (int i = 331; i <= 2*n; i++) cnt += max(0LL, c[i] - 1);
        // cout << cnt << '\n';
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) {
            cnt += a[i].second;
            if (i < a.size()-1 && a[i].first == a[i+1].first) continue;
            if (i != a.size()-1) {
                // cout << a[i].first << ' ' << cnt << '\n';
                ans += max(0LL, cnt-1) * (a[i+1].first - a[i].first);
            }
        }
        cout << ans << '\n';
    }
}