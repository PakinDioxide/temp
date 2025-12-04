/*
    author  : PakinDioxide
    created : 30/03/2025 16:01
    task    : orderset
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long

using namespace std;
using namespace __gnu_pbds;

template <class T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    pbds <ll> s;
    ll q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'I') {
            ll x;
            cin >> x;
            s.insert(x);
        } else if (c == 'D') {
            ll x;
            cin >> x;
            auto it = s.find(x);
            if (it != s.end()) s.erase(it);
        } else if (c == 'K') {
            ll k;
            cin >> k;
            if (s.size() < k) cout << "invalid\n";
            else cout << *s.find_by_order(k-1) << '\n';
        } else {
            ll k;
            cin >> k;
            cout << s.order_of_key(k) << '\n';
        }
    }
}