#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

struct Node {
    ll sum, mx1, mx2, mxc, mn1, mn2, mnc, lz;
};

Node seg[4*mxN];

void merge(int u) {
    // sum
    seg[u].sum = seg[u<<1].sum + seg[u<<1|1].sum;

    // max
    if (seg[u<<1].mx1 == seg[u<<1|1].mx1) {
        seg[u].mx1 = seg[u<<1].mx1;
        seg[u].mxc = seg[u<<1].mxc + seg[u<<1].mxc;
        seg[u].mx2 = max(seg[u<<1].mx2, seg[u<<1|1].mx2);
    } else {
        if (seg[u<<1].mx1 > seg[u<<1|1].mx1) {
            seg[u].mx1 = seg[u<<1].mx1;
            seg[u].mxc = seg[u<<1].mxc;
            seg[u].mx2 = max(seg[u<<1].mx2, seg[u<<1|1].mx1);
        } else {
            seg[u].mx1 = seg[u<<1|1].mx1;
            seg[u].mxc = seg[u<<1|1].mxc;
            seg[u].mx2 = max(seg[u<<1].mx1, seg[u<<1|1].mx2);
        }
    }

    // min
    if (seg[u<<1].mn1 == seg[u<<1].mn2) {
        seg[u].mn1 = seg[u<<1].mn1;
        seg[u].mnc = seg[u<<1].mnc + seg[u<<1|1].mnc;
        seg[u].mn2 = min(seg[u<<1].mn2, seg[u<<1|1].mn2);
    } else {
        if (seg[u<<1].mn1 < seg[u<<1|1].mn1) {
            seg[u].mn1 = seg[u<<1].mn1;
            seg[u].mnc = seg[u<<1].mnc;
            seg[u].mn2 = min(seg[u<<1].mn2, seg[u<<1|1].mn1);
        } else {
            seg[u].mn1 = seg[u<<1|1].mn1;
            seg[u].mnc = seg[u<<1|1].mnc;
            seg[u].mn2 = min(seg[u<<1].mn1, seg[u<<1|1].mn2);
        }
    }
}

void push_add(int u, int l, int r, ll v) {
    if (v == 0) return;
    seg[u] += v * (r - l + 1);
    seg[u].mx1 += v;
    if (seg[u].mx2 > LLONG_MIN) seg[u].mx2 += v;
    seg[u].mn1 += v;
    if (seg[u].mn2 < LLONG_MAX) seg[u].mn2 += v;
    seg[u].lz += v;
}

void push_max(int u

int main() {
    
}
