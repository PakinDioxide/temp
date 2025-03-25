/*
    author  : PakinDioxide
    created : 25/03/2025 21:53
    task    : guess
*/
#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

void solve() {
    vector <int> a(5);
    int ans1 = -1, ans2 = -1;
    for (int i = 0; i < 5; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            if ((a[i] + a[j]) % 2 != 0) continue;
            int x = (a[i] + a[j])/2, y = (a[j] - a[i])/2;
            if (x == 0 || y == 0) continue;
            if (x < y) swap(x, y);
            vector <int> b;
            b.push_back(x+y);
            b.push_back(x-y);
            b.push_back(x*y);
            b.push_back(x/y);
            b.push_back(x%y);
            sort(b.begin(), b.end());
            if (a == b) {
                ans1 = x, ans2 = y;
                break;
            }
        }
        if (ans1 != -1) break;
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}