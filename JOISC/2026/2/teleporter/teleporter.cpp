#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll T = 0;
    int n, q, k; cin >> n >> q >> k;
    vector <pair <int, ll>> v;
    while (q--) {
        int l, r; ll c; cin >> l >> r >> c;
        v.emplace_back(l, c);
        v.emplace_back(r, -c);
        T += c;
    }
    sort(v.begin(), v.end());
    ll curr = 0, mx = 0;
    for (int i = 0; i < (int) v.size(); i++) {
        curr += v[i].second;
        if (i < (int) v.size()-1 && v[i].first == v[i].second) continue;
        mx = max(mx, curr);
    }
    cout << T - mx << '\n';
}
