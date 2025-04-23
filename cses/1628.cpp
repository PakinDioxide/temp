/*
    author  : PakinDioxide
    created : 08/04/2025 18:34
    task    : 1628
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <ll> x, y;
ll n, K, a[45], cnt = 0;

void solve(int l, int r, ll k, int t) {
    if (l > r) {
        if (t) x.emplace_back(k);
        else y.emplace_back(k);
        return;
    }
    solve(l+1, r, k, t);
    solve(l+1, r, k+a[l], t);
}

int main() {
    cin >> n >> K;
    for (int i = 0; i < n; i++) cin >> a[i];
    solve(0, n/2, 0, 1);
    solve(n/2+1, n-1, 0, 0);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (auto &e : x) cnt += upper_bound(y.begin(), y.end(), K-e) - lower_bound(y.begin(), y.end(), K-e);
    cout << cnt << '\n';
}

/*
2^20 = 1e6

we can split the array into 2 parts

then we run a nlogn loop
*/