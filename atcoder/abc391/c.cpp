#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int cnt = 0, a[n+5], p[n+5];
    memset(a, 0, sizeof(a));
    memset(p, 0, sizeof(p));
    while (q--) {
        int t;
        cin >> t;
        if (t == 2) {cout << cnt << '\n'; continue;}
        int x, y;
        cin >> x >> y;
        if (p[x] > 0) a[p[x]]--;
        if (a[p[x]] == 0 && p[x] > 0) cnt--;
        if (a[y] == 0) cnt++;
        a[y]++;
        p[x] = y;
    }
}