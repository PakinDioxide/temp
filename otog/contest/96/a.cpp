/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
 
using namespace std;

bool comp(const pair <ll, ll> &a, const pair <ll, ll> &b) {
    return a.first-a.second <= b.first-b.second;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    pair <ll, ll> a[n];
    for (auto &[x, y] : a) cin >> y >> x;
    sort(a, a+n, comp);
    ll cnt = 0, cur = 0;
    for (auto &[x, y] : a) {
        if (cur < y) cnt += y-cur, cur = y;
        cur -= x;
    }
    cout << cnt << '\n';
}

