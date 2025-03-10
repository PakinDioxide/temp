#include <bits/stdc++.h>
#define ll long long

using namespace std;

int mex(int a, int b) {
    if (0 != a && 0 != b) return 0;
    else if (1 != a && 1 != b) return 1;
    return 2;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int a[n+1];
    for (int i = 1; i <= n; i++) a[i] = -1;
    int cnt = 0;
    for (int i = x; i <= y; i++) {
        cnt++;
        if (i == x) a[i] = 0;
        else a[i] = abs(a[i-1]-1);
        if (i == y) a[i] = mex(a[i-1], a[x]);
    }
    for (int i = (y%n)+1; i != x; i = (i%n)+1) {
        a[i] = abs(a[(i == 1 ? n : i-1)]-1);
        if (a[(i == 1 ? n : i-1)] == 2) a[i] = 0;
        if ((i%n)+1 == x) a[i] = mex(a[(i == 1 ? n : i-1)], a[x]);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}