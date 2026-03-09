#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 2e5+5;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    pair <ll, ll> a[n];
    for (auto &[v, c] : a) cin >> v >> c;
    int L = 
}

/*
# What if N = M

we have to find the maximum of beauty : min(C_Diff)
we could do C_diff = 2(max - min) should be min

so the problem reduces to

choose M cakes such that (V - 2(max - min)) is maximized
*/