#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n; cin >> n;
    ll a[n]; for (auto &e : a) cin >> e;
    ll cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (n-i+1) * i;
    stack <int> st;
    cout << cnt << '\n';
    ll L[n], R[n];
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        if (st.empty()) L[i] = i+1;
        else L[i] = i - st.top();
        // L[i]--;
        cout << L[i] << ' ';
        // if (i > 0) L[i] += L[i-1];
        st.emplace(i);
    } cout << '\n';
    while (!st.empty()) st.pop();
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] > a[i]) st.pop();
        if (st.empty()) R[i] = n-i;
        else R[i] = st.top() - i;
        // R[i]--;
        if (i < n-1) R[i] += R[i+1];
        cout << R[i] << ' ';
        st.emplace(i);
    }
    cout << '\n';
    // cnt = 0;
    for (int i = 0; i < n; i++) cnt -= L[i]*R[i] - (n-i), cout << L[i]*R[i]- (n-i) << '\n';// - (i+1)*(n-i);
    cout << cnt << '\n';
}
// (3, 4), (3, 2) = (3, 1)
// (3, 1), (3, 4), (3, 2), (1, 4), (1, 2) = (1, 1)
// 
