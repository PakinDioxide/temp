#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, a, b, x = 0, y = 0;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int ok = 0;
    for (int i = 0; i < 20; i++) {
        for (char k : s) {
            if (x == a && y == b) ok = 1;
            if (k == 'N') y++;
            else if (k == 'S') y--;
            else if (k == 'W') x--;
            else x++;
            if (x == a && y == b) ok = 1;
            if (ok) break;
        }
        if (ok) break;
    }    
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}