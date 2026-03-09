#include <bits/stdc++.h>
#define ll int

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    vector <vector <ll>> a(n, vector <ll> (m));
    for (auto &E : a) for (auto &e : E) cin >> e;
    for (auto &E : a) sort(E.begin(), E.end());
    ll mn = INT_MAX;
    for (auto &x : a[0]) {
        vector <pair <ll, ll>> V;
        for (auto &v : a) {
            auto it = lower_bound(v.begin(), v.end(), x);
            pair <ll, ll> X = {INT_MAX, INT_MIN};
            if (it != v.end()) { X.first = *it; }
            if (it != v.begin()) { X.second = *prev(it); }
            if (X.first > x) V.emplace_back(X);
        }
        sort(V.begin(), V.end());
        if (V.empty()) { mn = 0; break; }
        int sz = V.size();
        ll MN[sz+1];
        MN[sz] = x;
        for (int i = sz-1; i >= 0; i--) MN[i] = min(MN[i+1], V[i].second);
        if (MN[0] > INT_MIN) mn = min(mn, x - MN[0]);
        for (int i = 0; i < sz; i++) if (V[i].first < INT_MAX && MN[i+1] > INT_MIN) mn = min(mn, V[i].first - MN[i+1]);
    }
    cout << mn << '\n';
}

