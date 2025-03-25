/*
    author  : PakinDioxide
    created : 22/03/2025 20:19
    task    : calculator
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        ll n, cnt = 0;
        cin >> n;
        while (n > 0) n = (n % 2 == 0 ? n/2 : n-1), cnt++;
        cout << cnt << '\n';
    }
}