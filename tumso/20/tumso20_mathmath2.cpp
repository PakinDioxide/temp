#include <bits/stdc++.h>
#include "mathmath2.h"

using namespace std;

int main() {
    int n = init();
    vector <int> ans(n);
    for (int i = 0; i < n; i++) {
        int a = i%n, x = (i+1)%n, b = (i+2)%n, c = (i+3)%n, d = (i+4)%n;
        long long abc = (LCM(a, b, c) * GCD(a, b) * GCD(b, c) * GCD(a, c))/GCD(GCD(a, b), c);
        long long abd = (LCM(a, b, d) * GCD(a, b) * GCD(b, d) * GCD(a, d))/GCD(GCD(a, b), d);
        long long acd = (LCM(a, c, d) * GCD(a, c) * GCD(c, d) * GCD(a, d))/GCD(GCD(a, c), d);
        long long bcd = (LCM(b, c, d) * GCD(b, c) * GCD(c, d) * GCD(b, d))/GCD(GCD(B, c), d);
        ans[i] = sqrt((abc * abd / bcd) * acd / bcd);
    }
    answer(ans);
}