/*
    author  : PakinDioxide
    created : 19/04/2025 19:20
    task    : 901
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll l[n+1], r[n+2];
    l[0] = r[n+1] = 0;
    l[1] = a[1], r[n] = a[n];
    stack <pair <ll, int>> st;
    st.emplace(a[1], 1);
    for (int i = 2; i <= n; i++) {
        int idx = 0;
        while (!st.empty() && st.top().first > a[i]) st.pop();
        if (!st.empty()) idx = st.top().second;
        l[i] = (i-idx)*a[i] + l[idx];
        st.emplace(a[i], i);
    }
    while (!st.empty()) st.pop();
    st.emplace(a[n], n);
    ll mx = 0;
    for (int i = n-1; i >= 1; i--) {
        int idx = n+1;
        while (!st.empty() && st.top().first > a[i]) st.pop();
        if (!st.empty()) idx = st.top().second;
        r[i] = (idx-i)*a[i] + r[idx];
        st.emplace(a[i], i);
        mx = max(mx, l[i]+r[i]-a[i]);
    }
    cout << mx << '\n';
}