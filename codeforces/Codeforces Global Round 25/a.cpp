#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l;
    cin >> l;
    string s;
    cin >> s;
    int c = 0, cc = 0;
    if (s[l-1] == '1') c++;
    for (int i = 0; i < l-1; i++) {
        if (s[i] == '1') c++;
        if (s[i] == '1' && s[i+1] == '1') cc++;
    }
    if (c%2==1 || cc%2 == 1)
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--) solve();
}