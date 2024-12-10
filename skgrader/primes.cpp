#include <bits/stdc++.h>

using namespace std;

int isprime(int x) {
    for (int i = 2; i <= sqrt(x); i++) if (x % i == 0) return 0;
    return 1;
}

int main() {
    int cnt = 0;
    for (int i = 2; i <= sqrt(INT_MAX); i++) if (isprime(i))  cnt++;
    printf("%d\n", cnt);
}