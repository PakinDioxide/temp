#include "sum_product.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll mod = 1e9+7;

ll poww(ll x, ll y) {
	ll s = 1;
	while (y > 0) {
		if (y & 1LL) s *= x, s %= mod;
		x *= x, x %= mod;
		y >>= 1LL;
	}
	return s;
}

ll inv(ll x) { return poww(x, mod-2); }

int sum_product(int n, std::vector<int> a) {
	ll x = 0;
	// BRUTEFORCE - AC + TLE
	// ll p[n];
	// p[0] = a[0];
	// for (int i = 1; i < n; i++) p[i] = p[i-1]*a[i], p[i] %= mod;
	// for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
	// 	ll e = (p[j] * (i > 0 ? inv(p[i-1]) : 1)) % mod;
	// 	x += (e * poww(2, n-1-(j-i)-(j < n-1)-(i > 0))) % mod, x %= mod;
	// }
	// return x;

	ll y = 0;
	for (int i = 0; i < n; i++) {
		y *= a[i], y %= mod;
		y += (a[i] * poww(2, i-1)) % mod, y %= mod;
		x += y * poww(2, n-1-i-1), x %= mod;
	}
	return x;
}