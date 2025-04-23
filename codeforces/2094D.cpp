/*
    author  : PakinDioxide
    created : 13/04/2025 22:49
    task    : 2094D
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    vector <tuple <char, int, int>> A;
    for (auto &e : a) {
        if (A.empty() || get<0>(A.back()) != e) A.emplace_back(e, 1, 2);
        else get<1>(A.back())++, get<2>(A.back())+=2;
    }
    vector <pair <char, int>> B;
    for (auto &e : b) {
        if (B.empty() || B.back().first != e) B.emplace_back(e, 1);
        else B.back().second++;
    }
    int ok = 1;
    if (A.size() != B.size()) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < A.size(); i++) {
        auto [e, l, r] = A[i];
        if (e != B[i].first || !(l <= B[i].second && B[i].second <= r)) {ok = 0; break;}
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}