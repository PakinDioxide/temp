#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    map <char, int> mp;
    for (auto &e : b) mp[e]++;
    for (auto &e : a) mp[e]--;
    for (char c = 'a'; c <= 'z'; c++) if (mp[c] < 0) { cout << "Impossible\n"; return; }
    vector <char> v;
    int it = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        while (it < a.size() && a[it] <= c) cout << a[it++];
        while (mp[c]--) cout << c;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}