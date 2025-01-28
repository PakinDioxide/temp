#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (char &e : s) {
        e = 'a' + (e-'a'+k)%26;
        cout << e;
    }
}