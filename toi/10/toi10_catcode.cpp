/*
    author  : PakinDioxide
    created : 04/04/2025 12:23
    task    : toi10_catcode
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    string a[n];
    for (auto &e : a) cin >> e;
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        vector <int> ans;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) if (search(s.begin(), s.end(), a[i].begin(), a[i].end()) != s.end()) ans.emplace_back(i+1);
        if (ans.empty()) cout << "OK";
        else for (auto &e : ans) cout << e << ' ' ;
        cout << '\n';
    }
}