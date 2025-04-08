/*
    author  : PakinDioxide
    created : 07/04/2025 21:21
    task    : INVCNT
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    ll cnt = 0;
    Tree <pair <int, int>> s;
    for (int i = 0; i < n; i++) {
        cnt += s.size() - s.order_of_key(make_pair(a[i]+1, INT_MIN));
        s.insert(make_pair(a[i], i));
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}