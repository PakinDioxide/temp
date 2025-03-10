#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    pair <char, int> v[n][2];
    for (int i = 0; i < n; i++) cin >> v[i][0].first >> v[i][0].second >> v[i][1].first >> v[i][1].second;
    int k[n+1];
    k[n] = 0;
    for (int i = n-1; i > 0; i--) {
        if (v[i][0].first == v[i][1].first) {
            if (v[i][0].first == '+') k[i] = k[i+1];
            else if (v[i][0].second > v[i][1].second) k[i] = 0;
            else if (v[i][0].second < v[i][1].second) k[i] = 1;
            else k[i] = k[i+1];
        } else if (v[i][0].first == 'x') k[i] = 0;
        else k[i] = 1;
    }
    ll l = 1, r = 1;
    for (int i = 0; i < n; i++) {
        ll g = 0;
        if (v[i][0].first == 'x') g += (v[i][0].second-1)*l;
        else g += v[i][0].second;
        if (v[i][1].first == 'x') g += (v[i][1].second-1)*r;
        else g += v[i][1].second;
        if (k[i+1] == 0) l += g;
        else r += g;
    }
    cout << l + r << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}