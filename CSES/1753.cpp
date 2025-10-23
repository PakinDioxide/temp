/*
    author  : PakinDioxide
    created : 24/03/2025 01:37
    task    : 1753
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    string s = b + '#' + a;
    int n = s.size();
    int p[n], cnt = 0;
    p[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) j++;
        p[i] = j;
        if (p[i] == b.size()) cnt++;
    }
    cout << cnt << '\n';
}