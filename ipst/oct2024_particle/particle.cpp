#include "particle.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e6+5;

int n;
ll seg[4*mxN], lzz[4*mxN]; 
int lz[4*mxN];

void push(int u, int l, int r) {
    int mid = l + (r-l)/2;
    seg[u<<1] *= lz[u];
    lzz[u<<1] *= lz[u];
    lz[u<<1] *= lz[u];
    seg[u<<1] += lzz[u] * (mid - l + 1);
    lzz[u<<1] += lzz[u];
    seg[u<<1|1] *= lz[u];
    lz[u<<1|1] *= lz[u];
    lzz[u<<1|1] *= lz[u];
    seg[u<<1|1] += lzz[u] * (r - mid);
    lzz[u<<1|1] += lzz[u];
    lz[u] = 1, lzz[u] = 0;
    seg[u] = seg[u<<1] + seg[u<<1|1];
}

void build(int l, int r, int u) {
    lz[u] = 1, lzz[u] = 0;
    if (l == r) seg[u] = 0;
    else {
        int mid = l + (r-l)/2;
        build(l, mid, u<<1);
        build(mid+1, r, u<<1|1);
        seg[u] = seg[u<<1] + seg[u<<1|1];
    }
}

void q1(int l, int r, int x, int y, ll k, int u) {
    if (x <= l && r <= y) seg[u] *= -1, lz[u] *= -1, lzz[u] *= -1, seg[u] += k * (r - l + 1), lzz[u] += k;
    else {
        push(u, l, r);
        int mid = l + (r-l)/2;
        if (mid >= x) q1(l, mid, x, y, k, u<<1);
        if (mid+1 <= y) q1(mid+1, r, x, y, k, u<<1|1);
        seg[u] = seg[u<<1] + seg[u<<1|1];
    }
}

ll q2(int l, int r, int x, int y, int u) {
    if (x <= l && r <= y) return seg[u];
    else {
        push(u, l, r);
        int mid = l + (r-l)/2; ll s = 0;
        if (mid >= x) s += q2(l, mid, x, y, u<<1);
        if (mid+1 <= y) s += q2(mid+1, r, x, y, u<<1|1);
        return s;
    }
}

int q3(int l, int r, ll k, int u) {
    if (l == r) return l;
    else {
        push(u, l, r);
        int mid = l + (r-l)/2;
        if (seg[u<<1] >= k) return q3(l, mid, k, u<<1);
        else return q3(mid+1, r, k - seg[u<<1], u<<1|1);
    }
}

void init(int N) {
    n = N;
    build(0, n-1, 1);
}

void generateParticle(int L, int R, int P) {
    q1(0, n-1, L, R, P, 1);
}

long long countSize(int L, int R) {
    return q2(0, n-1, L, R, 1);
}

int bestPartition(int L, int R) {
    if (L == R) return L;
    ll S, K;
    ll M = (S = q2(0, n-1, L, R, 1))/2 + (K = (L == 0 ? 0 : q2(0, n-1, 0, L-1, 1)));
    int ans = max(L, q3(0, n-1, M, 1));
    if (ans == L) return L;
    ll k1 = q2(0, n-1, L, ans, 1),
       k2 = q2(0, n-1, L, ans-1, 1);
    if (abs(k1 - (S - k1)) < abs(k2 - (S - k2))) {
        M = k1 + K;
        return max(L, q3(0, n-1, M, 1));
    } else {
        M = k2 + K;
        return max(L, q3(0, n-1, M, 1));
    }
}

/*

just do a LAZY segment tree

Q3:
we want max (a_L + a_(L+1) + ... + a_A) * (a_(A+1) + a_(A+2) + ... + a_R)

we do binary search that abs((a_L .. a_A) - (a_(A+1) .. a_R)) is minimum

we do 2 times, first the L - R <= 0, second L - R >= 0

if we have multiple lz : p, q, r

x = p - x

x = q - (p - x)

x = - p + q + x

x = + p - q + r - x

x = r - (q - p) - x

x = r - (p - q)

*/