/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    map <pair <char, char>, set <int>> mp;
    vecotr <pair <char, char>> Q[q];
    for (int i = 0; i < q; i++) {
        char x, y; cin >> x >> y;
        Q[i] = make_pair(x, y);
        mp[make_pair(x, y)].emplace(i);
    }
    for (int i = 0; i < n; i++) {
        // check A
        if (a[i] == 'a') continue;
        if (mp[{a[i], 'a]}].size()) {
            mp[{a[i], 'a'}].erase(mp[{a[i], 'a'}].begin();
            a[i] = 'a';
            continue;
        } else {
            for (char i = 'a'; i <= 'c'; i++) {
                if (i == a[i] || i == 'a') continue;
                if (mp[{a[i], i}].size() && mp[{i, 'a'}].upper_bound(mp[{a[i], i
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

