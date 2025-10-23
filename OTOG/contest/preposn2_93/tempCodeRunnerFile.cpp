/*
    author  : PakinDioxide
    created : 23/03/2025 18:01
    task    : messy
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector <string> q;
    for (auto &e : s) {
        if (e == '/') q.push_back("");
        else q.back() += e;
    }
    map <string, int> cnt, ccnt;
    stack <string> st;
    for (int i = q.size(); i >= 0; i--) {
        if (q[i] == "." || q[i] == "") continue;
        else if (q[i] == "..") {
            int mn = 0;
            while (q[i] == "..") i--, mn--;
            i += mn+1;
        }
        else st.push(q[i]), cnt[q[i]]++;
    }
    while (!st.empty()) {
        auto e = st.top();
        st.pop();
        cout << "/" << e;
        if (cnt[e] > 1) cout << ccnt[e]++;
    }
    cout << '\n';
}