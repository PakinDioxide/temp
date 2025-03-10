#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size(), st = 0;
    cout << 1 << ' ' << n << ' ';
    string mx = "";
    while (s[st] == '1') st++;
    int sz = n-st, l = 1, r = 1;
    for (int i = 0; i < sz; i++) mx += '0';
    for (int i = 0; i < n-sz; i++) {
        int k = 0, val = 0, ok = 0;
        for (int j = i; j < i+sz; j++, k++) {
            if (s[k+st] != s[j]) val = 1;
            else val = 0;
            if (val+'0' > mx[k]) ok = 1;
            else if (val+'0' < mx[k] && !ok) break;
            if (ok) l = i+1, r = i+sz, mx[k] = val+'0';
        }
    }
    cout << l << ' ' << r << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}