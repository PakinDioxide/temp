// PakinDioxide SUB3+4
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll sum = 0, b[n+1];
    for (int i = 1; i <= n; i++) cin >> b[i], sum += b[i];
    int ok = 1;
    for (int i = 0; i < n-1; i++) {int x, y; cin >> x >> y; ok &= (x == 1 || y == 1);}
    if (!ok || n < 4) {for (int i = 0; i < n; i++) cout << sum << ' '; return 0;}
    priority_queue <pair <int, int>> q;
    for (int i = 2; i <= n; i++) {
        q.emplace(-b[i], i);
        if (q.size() > 3) q.pop();
    }
    int v[3][2];
    while (!q.empty()) v[q.size()-1][0] = -q.top().first, v[q.size()-1][1] = q.top().second, q.pop();
    cout << v[0][0] + v[1][0] + b[1] << ' ';
    for (int i = 2; i <= n; i++) {
        if (i == v[0][1]) cout << v[1][0] + v[2][0] + b[1] + b[i] << ' ';
        else if (i == v[1][1]) cout << v[0][0] + v[2][0] + b[1] + b[i] << ' ';
        else cout << v[0][0] + v[1][0] + b[1] + b[i] << ' ';
    }
}