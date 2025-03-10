#include <bits/stdc++.h>

using namespace std;

int main() {
    map <char, char> mp;
    mp['N'] = 'S';
    mp['S'] = 'N';
    mp['E'] = 'W';
    mp['W'] = 'E';
    string s;
    cin >> s;
    for (char i : s) cout << mp[i];
}