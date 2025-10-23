/*
    author  : PakinDioxide
    created : 16/03/2025 01:28
    task    : c
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string ans = "";
    if (n <= m) {
        int cnt = 0, dir = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dir != 0) cnt++;
                if (j == m-1) {
                    if (dir == 0) dir = 1;
                    else if (dir == 1) dir = 0;
                    ans += 'D';
                } else {
                    if (dir == 0) dir = 2;
                    else if (dir == 2) dir = 0;
                    if (i % 2 == 0) ans += 'R';
                    else ans += 'L';
                }
            }
        }
        ans.pop_back();
        cout << cnt << '\n';
        cout << "1 1 |\n";
        cout << ans.size() << '\n';
        cout << ans << '\n';
    } else {
        int cnt = 0, dir = 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dir != 0) cnt++;
                if (j == n-1) {
                    if (dir == 0) dir = 2;
                    else if (dir == 2) dir = 0;
                    ans += 'R';
                } else {
                    if (dir == 0) dir = 1;
                    else if (dir == 1) dir = 0;
                    if (i % 2 == 0) ans += 'D';
                    else ans += 'U';
                }
            }
        }
        ans.pop_back();
        cout << cnt << '\n';
        cout << "1 1 -\n";
        cout << ans.size() << '\n';
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}