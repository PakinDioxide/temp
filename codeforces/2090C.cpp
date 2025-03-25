/*
    author  : PakinDioxide
    created : 23/03/2025 12:32
    task    : 2090C
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    set <tuple <int, int, int, int, int>> st, st2;
    int mx = 0;
    for (; mx*(mx+1)/2 < n; mx++);
    for (int x = 0; x <= mx; x++) for (int y = 0; y <= mx-x; y++) {
        st.emplace(3*x+1 + 3*y+1, 3*x+1, 3*y+1, x, y);
        st.emplace(3*x+2 + 3*y+1, 3*x+2, 3*y+1, x, y);
        st.emplace(3*x+1 + 3*y+2, 3*x+1, 3*y+2, x, y);
        st.emplace(3*x+2+3*y+2+2, 3*x+2, 3*y+2, x, y);
        st2.emplace(3*x+1 + 3*y+1, 3*x+1, 3*y+1, x, y);
    }
    map <pair <int, int>, int> rm;
    for (auto &e : a) {
        if (e == 1) {
            auto &[w, xx, yy, x, y] = *st.begin();
            if (!rm[{x, y}]) {
                st2.erase(st2.find(make_tuple(3*x+1 + 3*y+1, 3*x+1, 3*y+1, x, y)));
                rm[{x, y}] = 1;
            }
            st.erase(st.begin());
            cout << xx << ' ' << yy << '\n';
        } else {
            auto [w, xx, yy, x, y] = *st2.begin();
            st2.erase(*st2.begin());
            rm[{x, y}] = 1;
            st.erase(st.find(make_tuple(w, xx, yy, x, y)));
            cout << xx << ' ' << yy << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}