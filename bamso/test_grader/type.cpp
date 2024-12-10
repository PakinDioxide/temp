#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0, rev = -1;
    for (char x : s) {
        if (x == '0') rev *= -1;
        if (x > '0' && x <= '9') cnt = (int) round((x-'0')*(x-'0') - 5.5*(x-'0')) % 26;
        while (cnt < 0) cnt += 26;
        if (x >= '0' && x <= '9') cout << x;
        else {
            char o;
            if (x >= 'A' && x <= 'Z') {
                o = (x - 'A' + cnt) % 26 + 'A';
                if (rev == 1) o = o - 'A' + 'a';
            } else {
                o = (x - 'a' + cnt) % 26 + 'a';
                if (rev == 1) o = o - 'a' + 'A';
            }
            cout << o;
        } 
    }
}