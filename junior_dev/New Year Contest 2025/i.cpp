// PakinDioxide - Bruteforce
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll cnt = 0, mod = 1e9+7;

int a[20], n;

void bf(ll vis, int c, int x, int y) {
    if (c == n) {cnt = (cnt+1)%mod; return;}
    for (int i = 0; i < n; i++) {
        if ((1 << i) & vis) continue;
        bf(vis | (1 << i), c+1, x, y+a[i]);
        if (x + a[i] <= y) bf(vis | (1 << i), c+1, x+a[i], y);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    bf(0, 0, 0, 0);
    cout << cnt;
}