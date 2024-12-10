#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n+1], cnt = 0;
    a[0] = a[n+1] = INT_MIN;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) if (a[i] > a[i-1] && a[i] > a[i+1]) cnt++;
    cout << cnt;
}