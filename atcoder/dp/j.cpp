/*
    author  : PakinDioxide
    created : 20/03/2025 02:55
    task    : j
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n], cnt = 0;
    for (auto &e : a) cin >> e, cnt += e;
    sort(a, a+n);
    double ans = 1;
    for (int i = 1; i < cnt; i++) {
        
    }
}