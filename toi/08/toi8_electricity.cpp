/*
    author  : PakinDioxide
    created : 24/03/2025 15:25
    task    : toi8_electricity
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto &e : a) cin >> e;
    deque <pair <int, int>> dq;
    dq.emplace_back(a[0], 0);
    for (int i = 1; i < n; i++) {
        while (dq.front().second < i-k) dq.pop_front();
        int nw = a[i] + dq.front().first;
        while (dq.back().first >= nw) dq.pop_back();
        dq.emplace_back(nw, i);
    }
    cout << dq.back().first << '\n';
}