/*
    author  : PakinDioxide
    created : 27/04/2025 13:05
    task    : a
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(m));
    for (auto &E : a) for (auto &e : E) cin >> e;
    sort(a.begin(), a.end());
    for (auto &E : a) {for (auto &e : E) cout << e << ' '; cout << '\n';}
}