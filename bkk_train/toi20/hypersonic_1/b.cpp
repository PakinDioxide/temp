/*
    author  : PakinDioxide
    created : 11/04/2025 12:54
    task    : b
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    ll ans = 0;
    map <char, ll> x;
    x['C'] = 12, x['O'] = 16, x['H'] = 1;
    stack <int> st;
    for (auto &e : s) {
        if (e == '(') st.emplace(-1);
        else if (e >= '0' && e <= '9') st.top() *= (e - '0');
        else if (e == ')') {
            ll k = 0;
            while (st.top() != -1) k += st.top(), st.pop();
            st.pop();
            st.emplace(k);
        } else st.emplace(x[e]);
    }
    while (!st.empty()) ans += st.top(), st.pop();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}