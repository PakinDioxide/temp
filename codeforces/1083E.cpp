/*
    author  : 
    created : 14/06/2025 23:21
    task    : 1083E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e6+5;

struct T {
    ll x, y, a;
};

T a[mxN];
int n;
ll dp[mxN];

ll calc(int p, ll x) {
    return a[p].x*x + dp[p];
}

double intersect(int p, int q) {
    return (double) (dp[q] - dp[p])/(a[q].x-a[p].x);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y >> a[i].a;
    sort(a+1, a+n+1, [&] (const T &p, const T &q) {
        return (p.x < q.x ? 1 : p.x == q.x ? p.y > q.y : 0);
    });
    dp[0] = 0;
    deque <int> cht;
    cht.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        while (cht.size() > 1 && calc(cht[0], -a[i].y) <= calc(cht[1], -a[i].y)) cht.pop_front();
        dp[i] = max(dp[i-1], a[i].x*a[i].y-a[i].a+calc(cht[0], -a[i].y));
        while (cht.size() > 1 && intersect(cht[cht.size()-2], cht[cht.size()-1]) <= intersect(cht[cht.size()-2], i)) cht.pop_back();
        cht.emplace_back(i);
    }
    cout << dp[n] << '\n';
}