/*
    author  : 
    created : 06/07/2025 21:54
    task    : 2124C
*/
#include <bits/stdc++.h>
#define ll long long
#define int ll

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    int a[n]; for (auto &e : a) cin >> e;
    int p[n+5]; memset(p, 0, sizeof(p));
    for (auto &e : a) p[e]++;
    for (int i = 1; i <= n; i++) p[i] += p[i-1];
    int x = n;
    while (x > 0) {
        if (p[x-1] + 1 >= k) x--;
        else break;
    }
    vector <int> b;
    for (auto &e : a) if (e <= x) b.emplace_back(e);
    int cnt = p[x] - k + 1, r = b.size()-1, cc = 0;
    for (int i = 0; i < r && i < b.size(); i++) {
        while (i < r && b[i] != b[r]) {
            if (b[i] == x) i++;
            else if (b[r] == x) r--;
            else { cout << "NO\n"; return; }
            cc++;
            if (cc > cnt) { cout << "NO\n"; return; }
        }
        r--;
    }
    cout << "YES\n";
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
there can be at most one number that appear odd times which that number must be in the middle

we can delete that number if
1. n(that number) + n(number that is less than that number) >= k

we will remove from great to least


*/