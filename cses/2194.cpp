/*
    author  : 
    created : 25/06/2025 19:50
    task    : 2194
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    pair <ll, ll> a[n]; for (auto &e : a) cin >> e.first >> e.second;
    sort(a, a+n);
    int idx = 0;
    ll d = LLONG_MAX;
    set <pair <ll, ll>> s;
    auto calc = [&] (pair <ll, ll> p, pair <ll, ll> q) {
        return (p.first-q.second)*(p.first-q.second) + (p.second-q.first)*(p.second-q.first);
    };
    for (auto &e : a) {
        ll sqt = ceil(sqrt(d));
        while (e.first - a[idx].first > sqt) s.erase(s.find(make_pair(a[idx].second, a[idx].first))), idx++;
        auto it = s.lower_bound(make_pair(e.second - sqt, LLONG_MIN));
        while (it != s.end() && (*it).first <= e.second + sqt) d = min(d, calc(*it, e)), it = next(it);
        s.emplace(e.second, e.first);
    }
    cout << d << '\n';
}