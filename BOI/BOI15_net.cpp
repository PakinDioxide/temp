#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int deg[n+1]; memset(deg, 0, sizeof(deg));
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, deg[u]++, deg[v]++;
    vector <int> v;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) v.emplace_back(i);
    cout << ceil((int) v.size() / 2.0) << '\n';
    for (int i = 0; i < v.size(); i += 2) {
        cout << v[i] << ' ' << v[(i+1) % ((int) v.size())] << '\n';
    }
}
