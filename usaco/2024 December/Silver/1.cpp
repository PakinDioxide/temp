#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    ll a[n], be = 0, el = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n-1, x = n/2-1, y = n/2, cnt = (n-1)/2;
    be = a[x] + a[y];
    for (int o = 0; o < n-2; o++) {
        if (o % 2 == 0) {
            if (a[l] > a[r]) el += a[l++];
            else if (a[l] == a[r] && a[l+1] > a[r-1]) el += a[l++];
            else el += a[r--];
            cnt--;
        } else {
            if (x == l) be += a[++y];
            else if (y == r) be += a[--x];
            else if (x-l < cnt && r-y < cnt) {
                if (a[x-1] > a[y+1]) be += a[--x];
                else be += a[++y];
            } else if (x-l < cnt) be += a[--x];
            else be += a[++y];
        }
    }
    cout << be << ' ' << el << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
