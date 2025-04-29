/*
    author  : PakinDioxide
    created : 28/04/2025 22:17
    task    : 2104E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> v[k], C(n+1, INT_MAX);
    C[n] = 0;
    for (int i = 0; i < n; i++) v[s[i] - 'a'].emplace_back(i);
    for (int i = 0; i < k; i++) v[i].emplace_back(n);
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            int id = upper_bound(v[j].begin(), v[j].end(), i) - v[j].begin();
            C[i] = min(C[i], C[v[j][id]] + 1);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string x;
        cin >> x;
        int idx = -1, ok = 1;
        for (auto &e : x) {
            int id = upper_bound(v[e-'a'].begin(), v[e-'a'].end(), idx) - v[e-'a'].begin();
            if (id == v[e-'a'].size()-1) {ok = 0; break;}
            idx = v[e-'a'][id];
        }
        if (ok) {
            // int cnt = 0;
            // while (idx != n) {
            //     int mx = 0;
            //     for (int i = 0; i < k; i++) {
            //         int id = upper_bound(v[i].begin(), v[i].end(), idx) - v[i].begin();
            //         if (id == v[i].size()) {mx = n; break;}
            //         mx = max(mx, v[i][id]);
            //     }
            //     idx = mx;
            //     cnt++;
            // }
            // cout << cnt << '\n';
            cout << C[idx] << '\n';
        } else cout << 0 << '\n';
    }
}

/*
it should be O(sum T)

"SUBSEQUENCE NOT SUBSTRING"


*/