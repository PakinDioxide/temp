#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector <pair <int, string>> v;
    int n; string k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        string s;
        getline(cin, s);
        vector <string> V;
        V.push_back("");
        for (char i : s) {
            if (i == ' ') V.push_back("");
            else V.back() += i;
        }
        int cnt = -1;
        for (int i = 1; i < V.size(); i++) if (V[i] == k) {cnt = i-1; break;}
        if (cnt > -1) v.emplace_back(cnt, V[0]);
    }
    sort(v.begin(), v.end());
    if (v.empty()) cout << -1;
    for (int i = 0; i < min(3, (int) v.size()); i++) cout << v[i].second << ' ';
    cout << '\n';
}