/*
    author  : PakinDioxide
    created : 17/03/2025 10:48
    task    : 2216
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n], cnt = 0;
    for (int i = 0; i < n; i++) {int e; cin >> e; a[e-1] = i;}
    for (int i = 1; i < n; i++) if (a[i] < a[i-1]) cnt++;
    cout << cnt+1 << '\n';
}