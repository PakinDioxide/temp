#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, ok = 1;
    scanf("%d", &n);
    pair <float, float> a[n];
    for (int i = 0; i < n; i++) scanf("%f %f", &a[i].first, &a[i].second);
    float sx, sy, ex, ey;
    scanf("%f %f %f %f", &sx, &sy, &ex, &ey);
    float minc = INT_MAX, mint = sqrt(pow(sx-ex, 2) + pow(sy-ey, 2));
    for (int i = 0; i < n; i++) {
        float p = sqrt(pow(a[i].first-ex, 2) + pow(a[i].second-ey, 2)), q = sqrt(pow(a[i].first-sx, 2) + pow(a[i].second-sy, 2)), r = mint;
        float s = (p+q+r)/2;
        float are = sqrt(s*(s-p)*(s-q)*(s-r));
        float h = are/r;
        float dis = sqrt(q*q-h*h);
        if ((p*p > q*q + r*r) || (q*q > p*p + r*r)) {
            if (p < q) h = p, dis = mint;
            else dis = 0, h = q;
        }
        printf("%f %f %f %f %f %f\n", a[i].first, a[i].second, h, dis, p, q);
        if (h <= dis) {ok = 0; break;} 
    }
    if (ok) printf("YES\n");
    else printf("NO\n");
}

int32_t main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}