/*
TASK: Touched
LANG: YourLanguage
AUTHOR: YourName
CENTER: YourCenter
*/
/*
    author  : PakinDioxide
    created : 08/04/2025 17:37
    task    : 1753_hash
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int ans[1000005];

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
const ll M = 1e9+9;
// const ll A = uniform_int_distribution<ll>(0, M - 1)(rng);
const ll A = 19937;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    if (q <= 500000) {
        unordered_map <ll, bool> vis;
        while (q--) {
            string s;
            cin >> s;
            ll k = 0;
            for (auto &e : s) k *= A, k %= M, k += e;
            if (vis[k]) cout << "YES\n";
            else cout << "NO\n";
            vis[k] = 1;
        }
        return 0;
    }
    vector <pair <ll, int>> v;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        ll k = 0;
        for (auto &e : s) k *= A, k %= M, k += e;
        v.emplace_back(k, i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < q; i++) {
        if (i > 0 && v[i-1].first == v[i].first) continue;
        ans[v[i].second] = 1;
    }
    for (int i = 0; i < q; i++) cout << (ans[i] ? "NO\n" : "YES\n");
}