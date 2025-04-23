/*
    author  : PakinDioxide
    created : 14/04/2025 20:38
    task    : d_bruteforce
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

tuple <ll, ll, ll> seg[(int)4e6+5], dp[(int)1e6+5];

void build(int l, int r, int node) {
    if (l == r) seg[node] = dp[l];
    else {
        int mid = l+(r-l)/2;
        build(l, mid, node*2+1);
        build(mid+1, r, node*2+2);
        seg[node] = max(seg[node*2+1], seg[node*2+2]);
    }
}

tuple <ll, ll, ll> qr(int l, int r, int x, int y, int node) {
    if (x <= l && r <= y) return seg[node];
    else {
        int mid = l+(r-l)/2;
        tuple <ll, ll, ll> k = {0, 0, 0};
        if (mid >= x) k = max(k, qr(l, mid, x, y, node*2+1));
        if (mid+1 <= y) k = max(k, qr(mid+1, r, x, y, node*2+2));
        return k;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    pair <ll, ll> a[t];
    ll ml = LLONG_MAX, mr = 0;
    for (auto &[l, r] : a) cin >> l >> r, ml = min(ml, l), mr = max(mr, r);
    for (ll tx = ml; tx <= mr; tx++) {
        dp[tx-ml] = {0, 0, 0};
        for (ll tk = 1; tk <= tx; tk++) {
            ll x = tx, k = tk, cnt = 0;
            while (x > 0 && k > 0 && x%k == 0) cnt++, x-=k, k--;//, cerr << x << ' ' << k << '\n';
            dp[tx-ml] = max(dp[tx-ml], make_tuple(cnt, tk, tx));
        }
    }
    for (int i = 0; i < 100; i++) {
        int k = i+ml;
        k = (k % 2 == 0 ? 2 : 3);
        cout << i+1 << ' ' << get<1>(dp[i]) << ' ' << k << (get<1>(dp[i]) != k ? " ERROR" : " ") << '\n';
    }
    // build(0, mr-ml, 0);
    // for (auto &[l, r] : a) {
    //     l -= ml, r -= ml;
    //     tuple <ll, ll, ll> k = qr(0, mr-ml, l, r, 0);
    //     cout << get<2>(k) << ' ' << get<1>(k) << '\n';
    // }
}

/*
1 1
2 2
3 3
4 2
5 5
6 2
7 7
8 2
9 3
10 2
11 11
12 2
13 13
14 2
15 3
16 4
17 17
18 2
19 19
20 2
21 3
22 2
23 23
24 2
25 5
26 2
27 3
28 4
29 29
30 2
31 31
32 2
33 3
34 2
35 35
36 6
37 37
38 2
39 3
40 4
41 41
42 2
43 43
44 2
45 5
46 2
47 47
48 2
49 7
50 2
51 3
52 4
53 53
54 2
55 55
56 2
57 3
58 2
59 59
60 2
61 61
62 2
63 3
64 8
65 5
66 6
67 67
68 2
69 3
70 2
71 71
72 2
73 73
74 2
75 3
76 4
77 77
78 2
79 79
80 2
81 3
82 2
83 83
84 2
85 5
86 2
87 3
88 4
89 89
90 2
91 7
92 2
93 3
94 2
95 95
96 6
97 97
98 2
99 3
100 10
*/