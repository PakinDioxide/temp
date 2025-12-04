#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;

int ask(int t, int i, int j) { cout << "? " << t << ' ' << i << ' ' << j << ' ' << (t == 1 ? n-1 : 1) << endl; int k; cin >> k; return k; }

void solve() {
    cin >> n;
    int a[n+1], v[n+1]; memset(a, 0, sizeof(a));
    for (int i = 1; i <= (n/2)*2; i += 2) v[i] = ask(1, i, i+1), v[i+1] = ask(2, i, i+1);
    int l = 2;
    for (int i = 3; i <= (n/2)*2; i += 2) {
        int k = ask(1, l, i);
        if (k == v[l-1]) {
            a[l-1] = v[l];
            a[l] = v[l-1];
            l = i+1;
        } else if (k == v[l]) {
            a[l-1] = v[l-1];
            a[l] = v[l];
            l = i+1;
        } else if (k == v[i]) {
            a[i] = v[i];
            a[i+1] = v[i+1];
        } else if (k == v[i+1]) {
            a[i+1] = v[i];
            a[i] = v[i+1];
        }
    }
    int mx = 0, id = 0;
    for (int i = 1; i <= n; i++) if (a[i] > mx) mx = a[i], id = i;
    if (mx == n) {
        a[l] = ask(1, l, id);
        a[l-1] = ask(1, l-1, id);
    } else if (mx == n-1) {
        int k = ask(1, l, id);
        if (k == n-1) a[l] = n, a[l-1] = ask(1, l, l-1);
        else a[l] = k, a[l-1] = n;
    } else a[l] = ask(2, l, id), a[l-1] = ask(2, l-1, id);
    int vis[n+1]; memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) vis[i] = 1;
    for (int i = 1; i <= n; i++) if (vis[i] == 0) a[n] = i;
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << endl;
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

/*
t = 1; 
if x > both, it return max(p_i, p_j)

x = n-1; p_i = n, return p_j == min(p_i, p_j)
x = n-1; p_i = n-1 return min(p_i, p_j) 

t = 2;
if x < both, it return min(p_i, p_j)

x = 1; p_i = 1, return max(p_i, p_j)
x = 1; p_j = 1, return p_i == max(p_i, p_j)

(a, b), (c, d), (e, f)

    ^    ^

    if min = a : b a ? ?
    if min = b : a b ? ?
    if min = c : ? ? c d
    if mid = d : ? ? d c

*/