#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k, ham = 0;
    cin >> k >> n;
    for (long long i = 0; i < n; i++) {
        long long a = i, b = i+1, c = k;
        while (c-- && (a || b)) {
            if ((a&1) != (b&1)) ham++;
            a = a >> 1;
            b = b >> 1;
        }
    }
    cout << ham;
}