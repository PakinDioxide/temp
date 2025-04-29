/*
    author  : PakinDioxide
    created : 24/04/2025 23:07
    task    : 2106F
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int ask(int x) {cout << "? 1 1 " << x << endl; int k; cin >> k; return k;}

void solve() {
    int n;
    cin >> n;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v;
    int f1 = ask(1);
    int a[n+1], rt = -1;
    if (abs(f1) == 1) {
        for (int i = 2; i <= n; i++) a[i] = ask(i) - f1;
        cout << "! " << f1 << ' ';
        for (int i = 2; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
    } else {
        int sum = 0;
        cout << "? 1 " << n-1 << ' ';
        for (int i = 2; i <= n; i++) cout << i << ' ';
        cout << endl;
        cin >> sum;
        int valrt = sum - (n-2)*f1;
        a[1] = f1 - valrt;
        for (int i = 2; i <= n; i++) {
            a[i] = ask(i) - f1;
            if (abs(a[i]) != 1) a[i] += f1;
        }
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}

/*
if x == 1 and 1 is root then f(1) = {-1, 1}
else if x == 1 and 1 isn't root then f(1) = {-2, 0, 2}

if x is root then f(x) = {-1, 1}
else if x == 1 then f(1) = {-2, 0, 2}
else f(x) = {-3, -1, 1, 3}
f(x) = val + f(1)
val = f(x) - f(1)
f(1) = val1 + f(rt)

*/