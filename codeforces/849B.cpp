/*
    author  : 
    created : 21/09/2025 14:47
    task    : 849B
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    for (int i = 1; i < n; i++) {
        int G = __gcd(a[i]-a[0], i);
        vector <int> P, Q;
        P.emplace_back(0);
        for (int j = 1; j < n; j++) {
            int GG = __gcd(a[j]-a[0], j);
            if (make_pair((a[i]-a[0])/G, i/G) == make_pair((a[j]-a[0])/GG, j/GG)) P.emplace_back(j);
            else Q.emplace_back(j);
        }
        if (Q.empty()) continue;
        int ok = 1;
        for (int j = 1; j < Q.size(); j++) {
            int GG = __gcd(a[Q[j]]-a[Q[0]], Q[j]-Q[0]);
            if (make_pair((a[i]-a[0])/G, i/G) != make_pair((a[Q[j]]-a[Q[0]])/GG, (Q[j]-Q[0])/GG)) { ok = 0; break; }
        }
        if (ok) { cout << "Yes\n"; return 0; }
    }
    for (int i = 1; i < n-2; i++) if (a[i+2] - a[i+1] != a[i+1] - a[i]) { cout << "NO\n"; return 0; }
    if (a[2] - a[1] == a[1] - a[0]) cout << "No\n";
    else cout << "Yes\n";
}