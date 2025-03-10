#include <bits/stdc++.h>

using namespace std;

int main() {
    long long q;
    scanf("%lld", &q);
    while (q--) {
        string a;
        cin >> a;
        long long ans = 0, sz = 0, n = a.size();
        for (long long i = 0; i < n-1; i++) {
            if (a[i] == '1') sz++;
            if (a[i+1] == '0' && sz > 0) ans += sz+1;
        }
        printf("%lld\n", ans);
    }
}