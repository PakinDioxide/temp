#include <bits/stdc++.h>
#define ll long long

using namespace std;

#define T tuple <ll, int, int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll a[n], b[n], s = 0;
    vector <pair <ll, ll>> A;
    for (auto &e : a) cin >> e, s += e;
    for (auto &e : b) cin >> e, e--;
    for (int i = 0; i < n; i++) if (b[i]) A.emplace_back(a[i], b[i]);
    sort(A.begin(), A.end());
    n = A.size();
    for (int i = 0; i < n; i++) a[i] = A[i].first, b[i] = A[i].second;
    // SUB 2/3
    // for (int i = 0; i < n; i++) s += a[i]*b[i]*(b[i]+1)/2*k/b[i];
    // cout << s << '\n';

    // SUB 4
    // priority_queue <tuple <ll, int, int>> q;
    // q.emplace(-(a[0]+a[1]), 1, 1);
    // map <pair <int, int>, bool> mp;
    // int c = 0;
    // while (c < k) {
    //     auto [w, l, r] = q.top(); q.pop(), w=-w;
    //     if (mp[{l, r}]) continue;
    //     mp[{l, r}] = 1;
    //     s += w, c++;
    //     if (l < b[0]) q.emplace(-(w+a[0]), l+1, r);
    //     if (r < b[1]) q.emplace(-(w+a[1]), l, r+1);
    // }
    // cout << s << '\n';

    // SUB 5
    // multiset <ll> dp;
    // dp.emplace(0);
    // for (int i = 0; i < n; i++) {
    //     s += a[i];
    //     multiset <ll> dp2 = dp;
    //     for (int j = 1; j < b[i]; j++) {
    //         if (!dp2.empty() && a[i]*j >= *prev(dp2.end()) && dp2.size() == k) break;
    //         for (auto &e : dp) {
    //             dp2.emplace(e+a[i]*j);
    //             while (dp2.size() > k) dp2.erase(prev(dp2.end()));
    //         }
    //     }
    //     dp = dp2;
    //     // for (auto &e : dp2) dp.emplace(e);
    //     // while (dp.size() > k) dp.erase(prev(dp.end()));
    // }
    // s *= k;
    // for (auto &e : dp) s += e;//, cout << e << ' ';
    // // cout << '\n';
    // cout << s << '\n';

    // SUB FULL
    // for (auto &e : b) e--;
    ll cnt = 1;
    // for (auto &e : a) s += e;
    s *= k;
    priority_queue <T, vector <T>, greater <T>> q;
    q.emplace(a[0], 0, 1);
    while (cnt < k) {
        auto [w, idx, c] = q.top(); q.pop();
        cnt++, s += w;
        if (idx == n) continue;
        if (c < b[idx]) q.emplace(w+a[idx], idx, c+1);
        if (idx < n-1) q.emplace(w+a[idx+1], idx+1, 1);
        if (idx < n-1 && c == 1) q.emplace(w+a[idx+1]-a[idx], idx+1, 1);
    }
    cout << s << '\n';

    // set <vector <int>> mp;
    // for (int i = 0; i < n; i++) A[i] = make_pair(a[i], b[i]-1), s += a[i];
    // sort(A, A+n);
    // // for (auto &[x, y] : A) cout << x << ' ' << y << '\n';
    // s *= k;

    // // Bruteforce O(nklogsth)
    // // priority_queue <tuple <ll, vector <int>>> q;
    // multiset <tuple <ll, vector <int>>> q;
    // q.emplace(0, vector <int>(n));
    // int c = k;
    // while (c) {
    //     auto [S, v] = *(q.begin()); q.erase(q.begin());
    //     if (mp.find(v) != mp.end()) continue;
    //     mp.emplace(v);
    //     // cout << "S " << S << '\n';
    //     // for (auto &E : v) cout << E << ' ';
    //     // cout << '\n';
    //     c--;
    //     s += S;
    //     // if (c == 0) break;
    //     // cout << "I ";
    //     for (int i = 0; i < n; i++) {
    //         if (v[i] == A[i].second) continue;
    //         // cout << i << ' ';
    //         v[i]++;
    //         q.emplace(S + A[i].first, v);
    //         while ((int)(q.size()) > c) q.erase(prev(q.end()));
    //         v[i]--;
    //     }
    //     // cout << '\n';
    // }
    // cout << s << '\n';
}
