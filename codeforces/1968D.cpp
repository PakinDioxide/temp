#include <bits/stdc++.h>

using namespace std;

int p[200005], a[200005], n, k, pb, ps;

void solve() {
    scanf("%d %d %d %d", &n, &k, &pb, &ps);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    long double sb = 0, ss = 0, db = 0, ds = 0;
    while (k > 0 && !(db && ds)) {
        k--;
        if (!db) {
            sb += (long double) a[pb];
            if (a[p[pb]] > a[pb]) pb = p[pb];
            else {sb += (long double) a[pb] * k; db = 1;}
        }
        if (!ds) {
            ss += (long double) a[ps];
            if (a[p[ps]] > a[ps]) ps = p[ps];
            else {ss += (long double) a[ps] * k; ds = 1;}
        }
    }
    if (sb > ss) printf("Bodya\n");
    else if (ss > sb) printf("Sasha\n");
    else printf("Draw\n");
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}