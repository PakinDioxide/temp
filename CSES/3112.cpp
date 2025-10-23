/*
    author  : PakinDioxide
    created : 13/05/2025 19:02
    task    : 3112
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool ask(int x) { cout << "? " << x << endl; string s; cin >> s; return (s == "YES"); }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int l = 1, r = 1e9, ans = 0;
    while (l <= r) {
        int x = l + (r-l)/2;
        if (ask(x)) l = x+1;
        else r = x-1, ans = x;
    }
    cout << "! " << ans << endl;
}