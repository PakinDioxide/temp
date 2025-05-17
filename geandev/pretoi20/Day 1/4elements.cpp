/*
    author  : PakinDioxide
    created : 11/05/2025 11:50
    task    : 4elements
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

int n, it = 0;
ll a[mxN], b[mxN], c[mxN], d[mxN];
vector <pair <ll, ll>> P;
multiset <pair <ll, ll>> ms;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i-1];
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]), b[i] += b[i-1];
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]), c[i] += c[i-1];
    for (int i = 1; i <= n; i++) scanf("%lld", &d[i]), d[i] += d[i-1];
    for (int i = 0; i <= n; i++) P.emplace_back(a[i]-c[i], b[i]-d[i]);
    sort(P.begin(), P.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());
    if (P.size() != n+1) return printf("0"), 0;
    ll d = LLONG_MAX;
    for (auto &[x, y] : P) {
        ll d2 = sqrt(d);
        while (x - P[it].first > d2) ms.erase(ms.find(make_pair(P[it].second, P[it].first))), it++;
        auto it = ms.lower_bound(make_pair(y-d2, LLONG_MIN));
        while (it != ms.end() && (*it).first <= y+d2) d = min(d, ((*it).first-y)*((*it).first-y)+((*it).second-x)*((*it).second-x)), it++;
        ms.emplace(y, x);
    }
    printf("%lld\n", d);
}

/*
(a-b)*a + (b-a)*b = (a-b)*(a-b)

a = a[r] - a[l]
b = b[r] - b[l]

a - b = a[r] - a[l] - b[r] + b[l]
      = a[r] - b[r] - (a[l] - b[l])

merge a, b

p[r] = a[r] - b[r]
p[l] = a[l] - b[l]

then do closest pair of point
*/