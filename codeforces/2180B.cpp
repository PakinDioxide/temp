#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n; cin >> n;
    string a[n];
    for (auto &e : a) cin >> e;
    string s = "";
    for (auto &e : a) {
        if (s + e < e + s) s += e;
        else s = e + s;
    }
    cout << s << '\n';
    return; 
    vector <pair <string, int>> v;
    for (int i = 0; i < n; i++) v.emplace_back(a[i], i);
    sort(v.begin(), v.end());
    int idx[n];
    for (int i = 0; i < n; i++) idx[v[i].second] = i;
    string L = "", R = "";
    for (int i = n-1; i > 0; i--) {
        if (L + a[i] + a[i-1] + R < L + a[i-1] + a[i] + R) L += a[i];
        else R = a[i] + R;
        continue;
        if (idx[i] < idx[i-1]) L += a[i];
        else R = a[i] + R;
    }
    cout << L << a[0] << R << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

