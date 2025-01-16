#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[m], ans = INT_MAX, cnt = 0;
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;
    sort(a, a+n);
    set <pair <int, int>> st;
    for (int i = 0; i < n-1; i++) st.emplace(b[i], i);
    for (int i = n-1; i < m; i++) {
        // cout <<"HA";
        int mx = 0;
        int idx = 0;
        st.emplace(b[i], i);
        if (st.size() > n) st.erase(st.find({b[i-n], i-n}));
        for (auto [e, idiii] : st) {
            mx = max(abs(e-a[idx]), mx);
            idx++;
            // cout <<e <<' ';
        }
        // cout << '\n';
        if (mx < ans) ans = mx, cnt= 1;
        else if (mx == ans) cnt++;
    }
    cout << ans << ' '<< cnt<<'\n';
}