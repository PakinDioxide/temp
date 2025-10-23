#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll x, y; cin >> x >> y;
    ll c = 2*(y/x);
    y %= x; cout << y << '\n';
    if (y*2 >= x) c++;
    cout << c << '\n';
}