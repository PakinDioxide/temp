#include <bits/stdc++.h>

using namespace std;

#define int long long
int mod = 1e9+7;

int32_t main() {
    vector <int> a;
    a.push_back(0), a.push_back(1), a.push_back(2), a.push_back(3);
    int q, s = 3, k;
    scanf("%lld", &q);
    while (q--) {
        scanf("%lld", &k);
        while (s < k) a.push_back((((4*a[s]%mod + 3*a[s-1]%mod)%mod + 2*a[s-2]%mod)%mod + 1)%mod), s++;
        printf("%lld\n", a[k]);
    }
}