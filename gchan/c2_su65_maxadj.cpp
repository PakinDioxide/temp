/*
    author  : PakinDioxide
    created : 13/03/2025 12:55
    task    : c2_su65_maxadj
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector <int> a;
    a.push_back(INT_MIN);
    while ((s[0] <= '9' && s[0] >= '0') || (s[0] == '-' && s.size() > 1)) {
        int n = stoi(s);
        a.push_back(n);
        cin >> s;
    }
    a.push_back(INT_MIN);
    for (int i = 1; i <= a.size() - 2; i++) if (a[i] > a[i-1] && a[i] > a[i+1]) cout << a[i] << ' ';
    cout << '\n';
}