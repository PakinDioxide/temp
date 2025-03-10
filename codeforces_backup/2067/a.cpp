#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve() {
    int x, y;
    cin >> x >> y;
    if (x == y-1 || ((x-y+1)%9 == 0 && (x-y+1 >= 0))) return 1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}