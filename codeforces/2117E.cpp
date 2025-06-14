/*
    author  : PakinDioxide
    created : 
    task    : 
*/
#include <bits/stdc++.h>
#define ll long long
#define db double
#define ld long double

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n], b[n];
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;
    int mx = -1;
    int A[n+1][2][2], B[n+1][2][2];
    auto psha = [&] (int x, int i) {
        int ii = i % 2;
        if (A[x][ii][0] <= i) A[x][ii][1] = A[x][ii][0], A[x][ii][0] = i;
        else if (A[x][ii][1] <= i) A[x][ii][1] = i;
    };
    auto pshb = [&] (int x, int i) {
        int ii = i % 2;
        if (B[x][ii][0] <= i) B[x][ii][1] = B[x][ii][0], B[x][ii][0] = i;
        else if (B[x][ii][1] <= i) B[x][ii][1] = i;
    };
    for (int i = 0; i <= n; i++) A[i][0][0] = A[i][0][1] = -2, A[i][1][0] = A[i][1][1] = -1;
    for (int i = 0; i <= n; i++) B[i][0][0] = B[i][0][1] = -2, B[i][1][0] = B[i][1][1] = -1;
    for (int i = 0; i < n; i++) psha(a[i], i);
    for (int i = 0; i < n; i++) pshb(b[i], i);
    for (int i = 1; i <= n; i++) {
        mx = max(mx, min(A[i][0][0], A[i][1][0]));
        mx = max(mx, min(B[i][0][0], B[i][1][0]));
        mx = max(mx, min(A[i][0][0], B[i][1][0]));
        mx = max(mx, min(A[i][1][0], B[i][0][1]));
        mx = max(mx, min(A[i][0][0], A[i][0][1]));
        mx = max(mx, min(A[i][1][0], A[i][1][1]));
        mx = max(mx, min(B[i][0][0], B[i][0][1]));
        mx = max(mx, min(B[i][1][0], B[i][1][1]));
        mx = max(mx, min(A[i][0][0], B[i][0][0]));
        mx = max(mx, min(A[i][1][0], B[i][1][0]));
    }
    cout << mx+1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
/*
    if same line, i % 2 != j % 2
    if different, i % 2 == j % 2
 */
