/*
    author  : 
    created : 25/06/2025 18:31
    task    : 1622
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s; cin >> s; sort(s.begin(), s.end());
    vector <string> v; v.emplace_back(s);
    while (next_permutation(s.begin(), s.end())) v.emplace_back(s);
    cout << v.size() << '\n';
    for (auto &e : v) cout << e << '\n';
}