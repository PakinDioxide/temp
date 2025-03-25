/*
    author  : PakinDioxide
    created : 11/03/2025 22:17
    task    : 2074E
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void ask(int a[3]) {cout << "? " << a[0] << ' ' << a[1] << ' ' << a[2] << '\n'; cout.flush();}
void ans(int a[3]) {cout << "! " << a[0] << ' ' << a[1] << ' ' << a[2] << '\n'; cout.flush();}

void solve() {
    int n;
    cin >> n;
    int a[3] = {1, 2, 3}, rt = 0;
    while (1) {
        int mid, k1, k2;
        ask(a);
        cin >> mid;
        if (mid == 0) {ans(a); return;}
        int b[3];
        for (int i = 0; i < 3; i++) b[i] = a[i];
        b[rt] = mid;
        ask(b);
        cin >> k1;
        if (k1 == 0) {ans(b); return;}
        b[rt] = a[rt];
        b[(rt+1)%3] = mid;
        ask(b);
        cin >> k2;
        if (k2 == 0) {ans(b); return;}
        a[0] = mid, a[1] = k1, a[2] = k2;
    }
}

// I asked too much -> grader responded with -1 and it got stuck in inf loop

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}