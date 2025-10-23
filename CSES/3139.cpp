/*
    author  : PakinDioxide
    created : 13/05/2025 19:26
    task    : 3139
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

bool ask(int x, int y) { cout << "? " << x << ' ' << y << endl; string s; cin >> s; return (s == "YES"); }

int n, a[mxN], ans[mxN];

void ms(int l, int r) {
    if (l == r) return;
    int mid = l + (r-l)/2;
    ms(l, mid), ms(mid+1, r);
    int x = l, y = mid+1, id = l, b[mxN];
    while (x <= mid && y <= r) {
        if (ask(a[x], a[y])) b[id++] = a[x++];
        else b[id++] = a[y++];
    }
    while (x <= mid) b[id++] = a[x++];
    while (y <= r) b[id++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = b[i];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    iota(a, a+n+1, 0);
    ms(1, n);
    for (int i = 1; i <= n; i++) ans[a[i]] = i;
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}