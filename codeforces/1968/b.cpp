#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    string a, b;
    cin >> a >> b;
    int l = 0;
    for (int i = 0; i < m && l < n; i++) if (b[i] == a[l]) l++;
    printf("%d\n", l);
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}