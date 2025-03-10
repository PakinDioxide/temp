#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool ok = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == 'i' && s[i+1] == 't') {ok = 1; break;}
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}