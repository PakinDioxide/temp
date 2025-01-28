#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    ll k = 1;
    for (int i = 1; i <= n; i++) {
        if (i % 10 == 8) k/=2;
        if (i % 3 == 0) k += i;
        if (i % 2 == 0) k = (k*1.1);
    }
    cout << k << '\n';
}