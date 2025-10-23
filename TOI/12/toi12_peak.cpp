#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> v;
    int a[n];
    for (int &e : a) cin >> e;
    for (int i = 0; i < n; i++) {
        if (i == 0) {if (a[i] > a[i+1]) v.emplace_back(a[i]);}
        else if (i == n-1) {if (a[i] > a[i-1]) v.emplace_back(a[i]);}
        else if (a[i] > a[i-1] && a[i] > a[i+1]) v.emplace_back(a[i]);
    }
    sort(v.begin(), v.end());
    vector <int> kv;
    for (int i = 0; i < v.size(); i++) if (i == 0 || v[i] != v[i-1]) kv.push_back(v[i]);
    if (kv.size() == 0) cout << -1 << '\n';
    else if (kv.size() < k) for (int e : kv) cout << e << '\n';
    else for (int i = 0; i < k; i++) cout << kv[kv.size()-i-1] << '\n';
}