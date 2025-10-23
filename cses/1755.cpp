/*
    author  : 
    created : 25/06/2025 18:10
    task    : 1755
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s; cin >> s; int n = s.size();
    map <char, int> cnt; for (auto &e : s) cnt[e]++;
    int ok = 0;
    for (char e = 'A'; e <= 'Z'; e++) if (cnt[e] % 2 == 1) ok++;
    if (ok > 1) { cout << "NO SOLUTION\n"; return 0; }
    string k = ""; for (int i = 0; i < n; i++) k.push_back(' ');
    int l = 0, r = n-1;
    for (char e = 'A'; e <= 'Z'; e++) if (cnt[e] % 2 == 0) for (int i = 0; i < cnt[e]; i++) {
        if (i % 2 == 0) k[l++] = e;
        else k[r--] = e;
    }
    for (char e = 'A'; e <= 'Z'; e++) if (cnt[e] % 2 == 1) for (int i = 0; i < cnt[e]; i++) {
        if (i % 2 == 0) k[l++] = e;
        else k[r--] = e;
    }
    cout << k << '\n';
}