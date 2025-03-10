#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, k = 1;
    for (; l < n; l++) if (s[l] == '1') break;
    int zr = l;
    while (l + 1 < n && s[l+1] == '1') l++;
    while (l < s.size() - 1) {
        if (k == 1) {
            s.erase(s.begin() + l + 1);
        } else {
            s.erase(s.begin() + l), l--;
            if (zr-1 == l) l++;
        }
        while (s[l] == '0' && l + 1 < s.size()) l++, zr++;
        while (l + 1 < s.size() && s[l+1] == '1') l++;
        k = -k;
        // cout << s << '\n';
        // cout << "X " << zr << ' ' << l << '\n';
    }
    int on = s.size() - zr;
    // cout << "ON : " << on << '\n';
    if (on > zr) cout << "YES\n";
    else if (on < zr) cout << "NO\n";
    else if (k == 1) cout << "YES\n";
    else cout << "NO\n";
    // int l = 0, sz = n, k = 1, z;
    // for (; l < n; l++) if (s[l] == '1') break;
    // sz = n-1;
    // int i = l;
    // while (i + 1 < n && s[i+1] == '1') i++;
    // z = l;
    // // cout << sz << ' ' << i << '\n';
    // while (i < sz) {
    //     if (k == 1) {
    //         s[i+1] = '1';
    //         l++, sz--;
    //         while (s[i+1] == '1') i++;
    //     } else {
    //         l++, sz--;
    //     }
    //     k *= -1;
    // }
    // if (sz - l + 1 > z) cout << "YES";
    // else if (sz - l + 1 < z) cout << "NO";
    // else if (sz - l + 1 == z) {
    //     if (k == 1) cout << "YES";
    //     else cout << "NO";
    // }
    // cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}