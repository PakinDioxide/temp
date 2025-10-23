#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a%b);}

int main() {
    int n;

    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    int m = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            m = max(gcd(a[i], a[j]), m);
        }
    }

    cout << m;
}
