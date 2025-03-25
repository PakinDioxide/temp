/*
    author  : PakinDioxide
    created : 17/03/2025 22:53
    task    : 09
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int k;
int a[1024];

int chk(int l, int r, int inv) {
    if (inv == 0) {
        if (a[r] == 0) return 0;
        if (l+1 == r) {/*cout << l << ' ' << r << ' ' << (a[l] == 0 && a[r] == 1) << '\n'; */return (a[l] == 0 && a[r] == 1);}
        int a1 = 0, a2 = 0;
        /*if (a[(l+r)/2] == 0) */a1 = max(chk(l, (l+r)/2, 1), chk(l, (l+r)/2, 0));
        a2 = chk((l+r)/2+1, r, 0);
        // if (a[r] == 0) a2 = chk((l+r)/2+1, r, 1);
        // else a2 = chk((l+r)/2+1, r, 0);
        // cout << l << ' ' << r << ' ' << min(a1, a2) << '\n';
        return min(a1, a2);
    } else {
        if (a[l] == 0) return 0;
        if (l+1 == r) {/*cout << l << ' ' << r << ' ' << (a[r] == 0 && a[l] == 1) << '\n'; */return (a[r] == 0 && a[l] == 1);}
        int a1 = 0, a2 = 0;
        /*if (a[l] == 0) */a1 = max(chk(l, (l+r)/2, 0), chk(l, (l+r)/2, 1));
        a2 = chk((l+r)/2+1, r, 1);
        // if (a[(l+r)/2+1] == 0) a2 = chk((l+r)/2+1, r, 0);
        // else a2 = chk((l+r)/2+1, r, 1);
        // cout << l << ' ' << r << ' ' << min(a1, a2) << '\n';
        return min(a1, a2);
    }
}

void solve() {
    for (int i = 0; i < (1 << k); i++) cin >> a[i];
    if (chk(0, (1 << k) - 1, 0)) cout << "yes\n";
    else cout << "no\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t >> k;
    while (t--) solve();
}
