#include <stdio.h>
#include <math.h>

int is_prime(int x) {
    if (x == 1) return 0;
    for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return 0;
    return 1;
}

int is_palindrome(int x) {
    if (x < 10) return 1;
    if (x < 100) return x % 11 == 0;
    if (x < 1000) return x % 10 == x/100;
    if (x < 10000) return (x % 10 == x/1000) && (x % 100 - x % 10 == (x % 1000 - x % 100)/10);
    return (x % 10 == x/10000) && ((x % 10000 - x % 1000)/100 == x % 100 - x % 10);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[4], ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                b[0] = a[i] + a[j] + a[k];
                if (!is_prime(b[0])) continue;
                for (int l = k+1; l < n; l++) {
                    int ok = 0;
                    b[1] = a[i] + a[j] + a[l], b[2] = a[i] + a[k] + a[l], b[3] = a[j] + a[k] + a[l];
                    if (!(is_prime(b[1]) && is_prime(b[2]) && is_prime(b[3]))) continue;
                    for (int p = 0; p < 4; p++) {
                        for (int q = p+1; q < 4; q++) {
                            if (is_palindrome(b[p] + b[q])) {
                                ok = 1;
                                break;
                            }
                        }
                        if (ok) break;
                    }
                    if (ok) {
                        ans += b[0] + a[l];
                        cnt++;
                    }
                }
            }
        }
    }
    printf("%d %d", ans, cnt);
}