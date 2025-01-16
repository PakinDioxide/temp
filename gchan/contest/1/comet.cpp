#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    int d, m, y, t, p, n, x[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%lld %lld %lld %lld %lld", &d, &m, &y, &t, &p);
    n = t*p;
    n += d - 2;
    d = 1;
    while (n >= 365) {
        n -= 365;
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) n--;
        y++;
    }
    if (n < 0) n = 365, y--;
    // printf("%lld\n", n);
    // printf("%lld %lld %lld\n", d, m, y);
    while (n >= x[m]) {
        n -= x[m];
        if (m == 2 && (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) n--;
        m++;
        if (m == 13) m = 1, y++;
    }
    if (n < 0) n = 28, m--;
    // printf("%lld\n", n);
    d += n;
    if (d == 0) {
        m--;
        if (m == 0) m == 12, y--;
        d = x[m];
        if (m == 2 && (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) d++;
    } 
    printf("%lld %lld %lld", d, m, y);
}