/*
ID: PakinDioxide
LANG: C++14
TASK: ride
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    int x = 1, y = 1;
    for (char i : a) x *= (i-'A'+1), x %= 47;
    for (char i : b) y *= (i-'A'+1), y %= 47;
    cout << (x == y ? "GO" : "STAY") << '\n';
}