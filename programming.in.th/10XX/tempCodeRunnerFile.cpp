#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    pair <long long, long long> a[2*m];
    for (long long i = 0; i < m; i++) {cin >> a[2*i].first >> a[2*i+1].first; a[2*i].second = 0; a[2*i+1].second = 1;}
    sort(a, a+2*m);
    char k;
    long long c = 0, ans = 0;
    cin >> k;
    if (k == 'G') k = 1;
    else if (k == 'B') k = 2;
    else k = 0;
    ans += k*n;
    for (long long i = 0; i < 2*m; i++) {
        pair <long long, long long> x = a[i];
        if (x.second == 0) c++;
        c %= 3;
        if (i == 2*m-1 || a[i+1].first > a[i].first) ans = ans - k + (k - c) + (k-c >= 0 ? 0 : 3);
        if (x.second == 1) c--;
    }
    cout << ans;
}