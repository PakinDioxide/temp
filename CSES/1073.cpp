/*
    author  : PakinDioxide
    created : 17/03/2025 13:31
    task    : 1073
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (auto &e : a) cin >> e;
    vector <int> d;
    for (auto &e : a) {
        int idx = upper_bound(d.begin(), d.end(), e) - d.begin();
        if (idx == d.size()) d.push_back(e);
        else d[idx] = e;
    }
    cout << d.size() << '\n';
}