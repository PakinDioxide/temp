#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

string s;

void ms(int l, int r) {
    if (l >= r) return;
    int mid = (l+r)/2;
    ms(l, mid), ms(mid+1, r);
    string a = "", b = "";
    for (int i = l; i <= mid; i++) a += s[i];
    for (int i = mid+1; i <= r; i++) b += s[i];
    string c = "";
    int x = 0, y = 0;
    while (x < a.size() && y < b.size()) {
        if (b[y] == '0') {
            c += a[x++];
        } else {
            if (b[y] - (y + a.size() - c.size()) > a[x]) c += (char) (b[y] - (y + a.size() - c.size())), y++;
            else c += a[x++];
        }
    }
    while (x < a.size()) c += a[x++];
    while (y < b.size()) c += b[y++];
    // cout <<c << ' ' << l << ' ' << r << '\n';
    for (int i = l; i <= r; i++) s[i] = c[i-l];
}

void solve() {
    cin >> s;
    ms(0, s.size()-1);
    cout << s << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}