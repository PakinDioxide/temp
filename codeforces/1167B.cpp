/*
    author  : PakinDioxide
    created : 19/04/2025 19:34
    task    : 1167B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

map <int, pair <int, int>> mp;

pair <int, int> ask(int x, int y) {cout << "? " << x << ' ' << y << endl; int k; cin >> k; return mp[k];}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int a[6] = {4, 8, 15, 16, 23, 42};
    for (int i = 0; i < 6; i++) for (int j = i+1; j < 6; j++) mp[a[i]*a[j]] = make_pair(a[i], a[j]);
    int ans[7];
    pair <int, int> x = ask(1, 2), y = ask(2, 3);
    if (x.first == y.first) ans[1] = x.second, ans[2] = x.first, ans[3] = y.second;
    else if (x.first == y.second) ans[1] = x.second, ans[2] = x.first, ans[3] = y.first;
    else if (x.second == y.first) ans[1] = x.first, ans[2] = x.second, ans[3] = y.second;
    else ans[1] = x.first, ans[2] = x.second, ans[3] = y.first;
    x = ask(4, 5), y = ask(5, 6);
    if (x.first == y.first) ans[4] = x.second, ans[5] = x.first, ans[6] = y.second;
    else if (x.first == y.second) ans[4] = x.second, ans[5] = x.first, ans[6] = y.first;
    else if (x.second == y.first) ans[4] = x.first, ans[5] = x.second, ans[6] = y.second;
    else ans[4] = x.first, ans[5] = x.second, ans[6] = y.first;
    cout << "! ";
    for (int i = 1; i <= 6; i++) cout << ans[i] << ' ';
    cout << endl;
}