/*
    author  : PakinDioxide
    created : 25/03/2025 14:56
    task    : 1188
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    set <pair <int, int>> st;
    s = '#' + s;
    int n = s.size();
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i-1]) st.emplace(i, i);
        else {
            auto [x, y] = *prev(st.end());
            st.erase(prev(st.end()));
            st.emplace(x, i);
        }
    }
    for (auto &[x, y] : st) cout << x << ' ' << y << '\n';
    int q;
    cin >> q;
    while (q--) {
        int idx;
        cin >> idx;
        auto it = st.lower_bound(make_pair(idx, idx));
        if ((*it).first == idx && (*it).second == idx) {

        } else if ((*it).first == idx) {
            if (it == st.begin()) {
                auto [x, y] = *it;
                st.erase(it);
                st.emplace(idx, idx);
                st.emplace(idx+1, y);
            } else {
                auto itp = prev(it);
                auto [x, y] = *it;
                auto [xx, yy] = *itp;
                st.erase(it);
                st.erase(itp);
                st.emplace(xx, yy+1);
                st.emplace(x+1, y);
            }
        } else if ((*it).second == idx) {
            if (it == prev(st.end())) {
                auto [x, y] = *it;
                st.erase(it);
                st.emplace(x, idx-1);
                st.emplace(idx, idx);
            } else {
                auto itp = prev(it);
                auto [x, y] = *it;
                auto [xx, yy] = *itp;
                st.erase(it);
                st.erase(itp);
                st.emplace(xx, yy+1);
                st.emplace(x+1, y);
            }
        } else {
            auto [x, y] = *it;
            st.erase(it);
            st.emplace(x, idx-1);
            st.emplace(idx, idx);
            st.emplace(idx+1, y);
        }
    }
}