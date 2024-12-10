#include "ricehub.h"
#include <bits/stdc++.h>

using namespace std;

int besthub(int n, int m, int a[], long long x) {
    int mx = 0, l = 1, r = 0;
    long long p[n+1];
    p[0] = 0;
    for (int i = 0; i < n; i++) p[i+1] = p[i] + a[i];
    while (r < n) {
        r++;
        while (p[r] - p[(l + r + 1)/2 - ((r - l) % 2)] - p[(l + r - 1)/2] + p[l-1] > x) l++;
        mx = max(mx, r - l + 1);
    }
    return mx;
}