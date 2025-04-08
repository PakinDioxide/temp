/*
    author  : PakinDioxide
    created : 29/03/2025 21:38
    task    : 2092B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnta = 0, cntb = 0, cca = 0, ccb = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cnta += (a[i] == '0'), cntb += (b[i] == '0'), cca++;
        else cnta += (b[i] == '0'), cntb += (a[i] == '0'), ccb++;
    }
    if (cnta >= cca && cntb >= ccb) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}