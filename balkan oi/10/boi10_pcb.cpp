/*
    author  : PakinDioxide
    created : 06/04/2025 01:07
    task    : boi10_pcb
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pair <ll, ll> a[n];
    for (auto &[l, r] : a) cin >> l >> r;
    sort(a, a+n);
    vector <ll> d;
    for (auto &[l, r] : a) {
        r = -r;
        int idx = lower_bound(d.begin(), d.end(), r) - d.begin();
        if (idx == d.size()) d.emplace_back(r);
        else d[idx] = r;
    }
    cout << d.size() << '\n';
}