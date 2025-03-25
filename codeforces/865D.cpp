/*
    author  : PakinDioxide
    created : 25/03/2025 11:31
    task    : 865D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll a[n], ans = 0;
    for (auto &e : a) cin >> e;
    priority_queue <ll> k;
    for (auto &e : a) {
        if (!k.empty() && -k.top() <= e) ans += e + k.top(), k.pop();
        k.emplace(-e);
    }
    cout << ans << '\n';
}