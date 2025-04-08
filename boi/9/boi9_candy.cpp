/*
    author  : PakinDioxide
    created : 06/04/2025 02:46
    task    : boi9_candy
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pair <ll, ll> A[n];
    tuple <ll, ll, ll> a[n];
    ll idx = 0, ans[n];
    for (auto &[x, y] : A) cin >> x >> y, a[idx] = make_tuple(x+y, -(x-y), idx), idx++;
    sort(a, a+n);
    vector <pair <ll, ll>> d;
    idx = 0;
    for (auto &[y, x, id] : a) {
        x=-x;
        int it = lower_bound(d.begin(), d.end(), make_pair(x, LLONG_MIN)) - d.begin();
        if (it == d.size()) {
            idx++;
            ans[id] = idx;
            d.emplace_back(x, idx);
        } else ans[id] = d[it].second, d[it].first = x;
    }
    cout << d.size() << '\n';
    for (int i = 0; i < n; i++) cout << A[i].first << ' ' << A[i].second << ' ' << ans[i] << '\n';
}

/*
read the observation sol - same wagon when they are fully coverd within another
*/