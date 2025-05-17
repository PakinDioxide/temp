/*
    author  : PakinDioxide
    created : 04/05/2025 19:22
    task    : D2_A
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ask(int x, int y) { cout << "? " << x << ' ' << y << endl; ll k; cin >> k; return k; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll k = ask(1, n);
    ll l[n+1], r[n+1];
    vector <pair <ll, int>> v;
    for (int i = 2; i < n; i++) {l[i] = ask(1, i), r[i] = ask(i, n); if (l[i] + r[i] == k) v.emplace_back(l[i], i); }
    sort(v.begin(), v.end());
    cout << "! " << v.size() + 2 << ' ' << 1 << ' ';
    for (auto &[x, y] : v) cout << y << ' ';
    cout << n << endl;
}