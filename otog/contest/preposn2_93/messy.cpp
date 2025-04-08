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
    stack <pair <string, int>> st;
    map <string, int> cnt, ccnt;
    for (auto &e : q) {
        if (e == "." || e == "") continue;
        else if (e == "..") {if (!st.empty()) st.pop();}
        else st.emplace(e, cnt[e]), cnt[e]++;
    }
    stack <pair <string, int>> ans;
    while (!st.empty()) {
        auto e = st.top();
        st.pop();
        ans.push(e);
    }
    int kfkfkfk = 0;
    cout << "/";
    while (!ans.empty()) {
        auto [e, id] = ans.top();
        ans.pop();
        if (kfkfkfk) cout << "/";
        kfkfkfk = 1;
        cout << e;
        if (cnt[e] > 1) cout << id;
    }
    cout << '\n';
}