#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s; cin >> s;
    stack <ll> st;
    for (auto &e : s) {
        if (e == '-') continue;
        if (e == '>') st.emplace(-10);
        if (e == '(') st.emplace(-1);
        if (e == ')') {
            if (st.top() == -1) { st.pop(), st.emplace(0); continue; }
            while (1) {
                int k = st.top(); st.pop();
                if (st.top() == -1) { st.pop(), st.emplace(k); break; }
                st.pop();
                int kk = st.top(); st.pop(); st.emplace(max(kk+1, k));
            }
        }
    }
    while (st.size() > 1) {
        int k = st.top(); st.pop();
        st.pop();
        int kk = st.top(); st.pop(); st.emplace(max(kk+1, k));
    }
    cout << st.top() << '\n';
}