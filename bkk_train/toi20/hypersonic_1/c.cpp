/*
    author  : PakinDioxide
    created : 11/04/2025 13:03
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (auto &e : a) cin >> e;
    stack <pair <ll, int>> st;
    ll l[n], r[n], p[n], s[n];
    p[0] = a[0], s[n-1] = a[n-1];
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first <= a[i]) st.pop();
        if (st.empty()) l[i] = 0;
        else l[i] = st.top().second+1;
        st.emplace(a[i], i);
        if (i > 0) p[i] = p[i-1] + a[i];
    }
    while (!st.empty()) st.pop();
    for (int i = n-1; i > 0; i--) {
        while (!st.empty() && st.top().first <= a[i]) st.pop();
        if (st.empty()) r[i] = n-1;
        else r[i] = st.top().second-1;
        st.emplace(a[i], i);
        if (i < n-1) s[i] = s[i+1] + a[i];
    }
    ll mx = 0;
    for (int i = 0; i < n; i++) mx = max(mx, a[i]*(r[i]-l[i]+1)*((l[i]-1 >= 0 ? p[l[i]-1] : 0) + (r[i]+1 < n ? s[r[i]+1] : 0)));
    cout << mx << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}