/*
    author  : PakinDioxide
    created : 14/03/2025 03:48
    task    : 2015_Dec_B_1
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b <= c || d <= a) cout << b-a + d-c << '\n';
    else cout << max(0, max(b, d) - min(a, c)) << '\n';
}