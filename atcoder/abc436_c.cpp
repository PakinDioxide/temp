#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    map <pair <int, int>, int> a;
    int cnt = 0;
    while (m--) {
        int x, y; cin >> x >> y;
        if (a[{x, y}] == 0 && a[{x+1, y}] == 0 && a[{x, y+1}] == 0 && a[{x+1, y+1}] == 0) cnt++, a[{x, y}] = a[{x+1, y}] = a[{x, y+1}] = a[{x+1, y+1}] = 1;
    }
    cout << cnt << '\n';
}

