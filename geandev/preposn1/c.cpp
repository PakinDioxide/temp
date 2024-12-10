#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q, x;
    multiset <int> s;
    stack <int> st;
    cin >> q;
    while (q--) {
        string str;
        cin >> str;
        if (str == "Push") cin >> x, s.insert(x), st.push(x);
        else {
            s.erase(s.find(st.top()));
            st.pop();
        }
        cout << *s.rbegin() << '\n';
    }
}