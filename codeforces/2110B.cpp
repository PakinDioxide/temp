/*
    author  : PakinDioxide
    created : 24/05/2025 21:38
    task    : 2110B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve() {
    string s; cin >> s; int n = s.size();
    int cnt = 0, c = 0;
    for (auto &e : s) {
        if (e == '(') c++;
        else c--;
        cnt += !c;
    }
    return cnt>1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}