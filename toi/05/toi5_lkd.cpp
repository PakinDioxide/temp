#include <bits/stdc++.h>

using namespace std;

void cnv(string s) {
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') n += pow(2, s.size()-i-1);
    }
    cout << (char) n;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int st = 1, n;
    cin >> n;
    while (n--) {
        string s, ans = "", k = "";
        cin >> s;
        if (s.size() != 16) break;
        for (int i = 0; i < s.size(); i+=2) {
            k = "";
            k += s[i], k += s[i+1];
            if (st == 1) {
                if (k == "00") ans += '0';
                else st = 2, ans += '1';
            } else if (st == 2) {
                if (k == "01") st = 4, ans += '1';
                else st = 3, ans += '0';
            } else if (st == 3) {
                if (k == "00") st = 2, ans += '1';
                else st = 1, ans += '0';
            } else {
                if (k == "10") ans += '1';
                else st = 3, ans += '0';
            }
        }
        cnv(ans);
    }
}