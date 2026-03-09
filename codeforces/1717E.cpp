#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
}

/*
lcm(c, x) = c*x/gcd(c, x)
          = c * gcd(a, b) / gcd(a, b, c)
what if loop for c : c * SIGMA(gcd(a, b)/gcd(a, b, c))


x / gcd(c, x)

x = p1^a1 * p2^a2 * p3^a3 * ...
c = p1^b1 * p2^b2 * p3^b3 * ...
gcd(c, x) = p1^min(a1, b1) * p2^min(a2, b2) * p3^min(a3, b3) * ...

x / gcd(c, x) = p1^[a1 - min(a1, b1)] * p2^[a2 - min(a2, b2)] * ...
              = p1^max(0, a1-b1) * p2^max(0, a2-b2) * ...
*/