#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    vector <pair <int, int>> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.emplace_back(x, i);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector <int> vv;
    vv.emplace_back(v[0].second * 2 + 1);
    for (int i = 1; i < n; i++) {
        cout << v[i-1].second * 2 + 1 << ' ' << v[i].second * 2 + 1 << '\n';
        vv.emplace_back(v[i].second * 2 + 1);
    }
    for (int i = 0; i < n; i++) {
        cout << vv[v[i].first + i - 1] << ' ' << v[i].second * 2 + 2 << '\n';
        if (v[i].first + i >= vv.size()) vv.emplace_back(v[i].second * 2 + 2);
    }
}

