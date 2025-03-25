/*
    author  : PakinDioxide
    created : 12/03/2025 20:07
    task    : 1164
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, mx = 0;
    cin >> n;
    int a[n];
    vector <tuple <int, int, int>> v;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v.emplace_back(l, 1, i);
        v.emplace_back(r+1, -1, i);
    }
    sort(v.begin(), v.end());
    set <int> st;
    for (auto [idx, k, id] : v) {
        if (k == -1) st.insert(a[id]);
        else {
            if (st.empty()) a[id] = ++mx;
            else {
                a[id] = *st.begin();
                st.erase(st.begin());
            }
        }
    }
    cout << mx << '\n';
    for (auto i : a) cout << i << ' ';
    cout << '\n';
}