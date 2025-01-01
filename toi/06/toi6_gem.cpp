#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    pair <int, int> a[n];
    int no[m+1];
    for (int i = 0; i < n; i++) cin >> a[i].f >> a[i].s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        no[x] = y;
        no[y] = x;
    }
    
}

int main() {
    for (int i = 0; i < 5; i++) solve();
}