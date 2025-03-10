#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    long long t;
    scanf("%lld", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);
        long long a[n+1], b[n+1], c[n+1], tot = 0, ok = 0;
        a[0] = b[0] = c[0] = 0;
        for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i-1];
        for (long long i = 1; i <= n; i++) scanf("%lld", &b[i]), b[i] += b[i-1];
        for (long long i = 1; i <= n; i++) scanf("%lld", &c[i]), c[i] += c[i-1];
        tot = ceil((double) a[n]/3);
        for (long long i = 1; i < n-1; i++) {
            if (a[i] >= tot) {
                for (long long j = i+1; j < n; j++) {
                    if (b[j] - b[i] >= tot) {
                        if (c[n] - c[j] >= tot) {
                            ok = 1;
                            printf("%lld %lld %lld %lld %lld %lld\n", 1LL, i, i+1LL, j, j+1LL, n);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (ok) continue;
        for (long long i = 1; i < n-1; i++) {
            if (a[i] >= tot) {
                for (long long j = i+1; j < n; j++) {
                    if (c[j] - c[i] >= tot) {
                        if (b[n] - b[j] >= tot) {
                            ok = 1;
                            printf("%lld %lld %lld %lld %lld %lld\n", 1LL, i, j+1LL, n, i+1LL, j);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (ok) continue;
        for (long long i = 1; i < n-1; i++) {
            if (b[i] >= tot) {
                for (long long j = i+1; j < n; j++) {
                    if (a[j] - a[i] >= tot) {
                        if (c[n] - c[j] >= tot) {
                            ok = 1;
                            printf("%lld %lld %lld %lld %lld %lld\n", i+1LL, j, 1LL, i, j+1LL, n);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (ok) continue;
        for (long long i = 1; i < n-1; i++) {
            if (b[i] >= tot) {
                for (long long j = i+1; j < n; j++) {
                    if (c[j] - c[i] >= tot) {
                        if (a[n] - a[j] >= tot) {
                            ok = 1;
                            printf("%lld %lld %lld %lld %lld %lld\n", j+1LL, n, 1LL, i, i+1LL, j);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (ok) continue;
        for (long long i = 1; i < n-1; i++) {
            if (c[i] >= tot) {
                for (long long j = i+1; j < n; j++) {
                    if (b[j] - b[i] >= tot) {
                        if (a[n] - a[j] >= tot) {
                            ok = 1;
                            printf("%lld %lld %lld %lld %lld %lld\n", j+1LL, n, i+1LL, j, 1LL, i);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (ok) continue;
        for (long long i = 1; i < n-1; i++) {
            if (c[i] >= tot) {
                for (long long j = i+1; j < n; j++) {
                    if (a[j] - a[i] >= tot) {
                        if (b[n] - b[j] >= tot) {
                            ok = 1;
                            printf("%lld %lld %lld %lld %lld %lld\n", i+1LL, j, j+1LL, n, 1LL, i);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (ok) continue;
        printf("-1\n");
        // // printf("TOT : %lld\n", tot);
        // for (long long lb = 2; lb < n; lb++) {
        //     if (a[lb-1] < tot && b[lb-1] < tot && c[lb-1] < tot) continue;
        //     for (long long lc = lb + 1; lc <= n; lc++) {
        //         if (a[lb-1] >= tot) {
        //             if (b[lc-1] - b[lb-1] >= tot && c[n] - c[lc-1] >= tot) {
        //                 ok = 1;
        //                 printf("%lld %lld %lld %lld %lld %lld\n", 1LL, lb-1LL, lb, lc-1LL, lc, n);
        //                 break;
        //             } else if (c[lc-1] - c[lb-1] >= tot && b[n] - b[lc-1] >= tot) {
        //                 ok = 1;
        //                 printf("%lld %lld %lld %lld %lld %lld\n", 1LL, lb-1LL, lc, n, lb, lc-1);
        //                 break;
        //             }
        //         }
        //         if (b[lb-1] >= tot) {
        //             if (a[lc-1] - a[lb-1] >= tot && c[n] - c[lc-1] >= tot) {
        //                 ok = 1;
        //                 printf("%lld %lld %lld %lld %lld %lld\n", lb, lc-1LL, 1LL, lb-1LL, lc, n);
        //                 break;
        //             } else if (c[lc-1] - c[lb-1] >= tot && a[n] - a[lc-1] >= tot) {
        //                 ok = 1;
        //                 printf("%lld %lld %lld %lld %lld %lld\n", lc, n, 1LL, lb-1LL, lb, lc-1);
        //                 break;
        //             }
        //         }
        //         if (c[lb-1] >= tot) {
        //             if (c[lb-1] >= tot && a[lc-1] - a[lb-1] >= tot && b[n] - b[lc-1] >= tot) {
        //                 ok = 1;
        //                 printf("%lld %lld %lld %lld %lld %lld\n", lb, lc-1LL, lc, n, 1LL, lb-1);
        //                 break;
        //             } else if (c[lb-1] >= tot && b[lc-1] - b[lb-1] >= tot && a[n] - a[lc-1] >= tot) {
        //                 ok = 1;
        //                 printf("%lld %lld %lld %lld %lld %lld\n", lc, n, lb, lc-1LL, 1LL, lb-1);
        //                 break;
        //             }
        //         } 
        //     }
        //     if (ok) break;
        // }
        // if (!ok) printf("-1\n");
    }
}