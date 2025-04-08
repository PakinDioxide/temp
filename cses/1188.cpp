/*
    author  : PakinDioxide
    created : 07/04/2025 19:40
    task    : 1188
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string a;
    cin >> a;
    int n = a.size();
    a = " " + a;
    set <int> s;
    multiset <int> ans;
    for (int i = 1; i <= n; i++) if (a[i] != a[i-1]) s.emplace(i);
    s.emplace(0);
    s.emplace(n+1);
    auto it = next(s.begin());
    while (next(it) != s.end()) ans.emplace(*next(it) - *it), it++;
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        it = prev(s.upper_bound(x));
        int sz = *next(it) - *it;
        if (*it == x && *next(it) == x+1) {
            s.erase(next(it));
            s.erase(it);
            s.emplace(1);
            s.emplace(n+1);
            ans.erase(sz);
            it = prev(s.upper_bound(x));
            ans.emplace(*next(it) - *it);
        } else if (*it == x) {
            s.erase(*it);
            s.emplace(x+1);
            s.emplace(1);
            s.emplace(n+1);
            ans.erase(sz);
            ans.emplace(*next(it) - *it);
        } else if (*next(it) == x+1) {
            s.erase(next(it));
            s.emplace(x);
            s.emplace(1);
            s.emplace(n+1);
            ans.erase(sz);
            
        }
    }
}