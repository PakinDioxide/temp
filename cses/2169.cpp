/*
    author  : PakinDioxide
    created : 17/03/2025 14:24
    task    : 2169
*/
#include <bits/stdc++.h>

using namespace std;
int fen[2][400005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    tuple <int, int, int> a[n], b[n];
    vector <int> st;
    for (auto &[r, l, id] : a) cin >> l >> r, st.emplace_back(r), st.emplace_back(l);
    sort(st.begin(), st.end());
    int idxx = 1, ans[2][n];
    for (auto &[r, l, id] : a) r = lower_bound(st.begin(), st.end(), r) - st.begin() + 1, l = lower_bound(st.begin(), st.end(), l) - st.begin() + 1, idxx = max({idxx, l+1, r+1});
    for (int i = 0; i < n; i++) get<2>(a[i]) = i, b[i] = a[i], swap(get<0>(b[i]), get<1>(b[i])), get<1>(a[i]) *= -1, get<1>(b[i]) *= -1;
    sort(a, a+n);
    sort(b, b+n);
    auto add = [&] (int idx, int x, int k) {
        for (int i = idx; i < idxx; i += i & (-i)) fen[k][i] += x;
    };
    auto sum = [&] (int idx, int k) {
        int s = 0;
        for (int i = idx; i > 0; i -= i & (-i)) s += fen[k][i];
        return s;
    };
    for (auto &[r, l, id] : a) {
        l = -l;
        ans[0][id] = sum(r, 0) - sum(l-1, 0);
        add(l, 1, 0);
    }
    for (auto &[l, r, id] : b) {
        r = -r;
        ans[1][id] = sum(idxx-1, 1) - sum(r-1, 1);
        add(r, 1, 1);
    }
    for (int i = 0; i < n; i++) cout << ans[0][i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << ans[1][i] << ' ';
    cout << '\n';
}