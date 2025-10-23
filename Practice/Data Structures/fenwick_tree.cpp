#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 200005;
int fen[N], val[N], n;

void upd(int idx, int x) {
    for (; idx <= n; idx += (idx & -idx)) fen[idx] += x;
}

int sum(int l, int r) {
    int s = 0;
    for (; r > 0; r -= (r & -r)) s += fen[r];
    l--;
    for (; l > 0; l -= (l & -l)) s -= fen[l];
    return s;
}

int32_t main() {
    int q;
    scanf("%lld %lld", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &val[i]), upd(i, val[i]);
    while (q--) {
        int k, a, b;
        scanf("%lld %lld %lld", &k, &a, &b);
        if (k == 1) {
            upd(a, b - val[a]);
            val[a] = b;
        } else printf("%lld\n", sum(a, b));
    }
}