/*
    author  : PakinDioxide
    created : 14/04/2025 14:35
    task    : toi20_orbs_pbds
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, l, a, b;
    cin >> n >> l >> a >> b;
    Tree <ll> s;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }
    a--, b--;
    for (int i = 0; i < l; i++) {
        auto x = s.find_by_order(a), y = s.find_by_order(b);
        ll X = *x, Y = *y;
        s.erase(y), s.erase(x);
        s.insert(Y-X), s.insert((X+Y)/2);
    }
    for (auto &e : s) cout << e << ' ';
    cout << '\n';
}