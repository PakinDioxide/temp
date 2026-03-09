#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    srand(time(0));
    int n = rand() % 50 + 1, m = rand() % 50 + 1;
    int p = rand() % n, q = rand() % m;
    cout << n << ' ' << m << ' ' << p << ' ' << q;
}
