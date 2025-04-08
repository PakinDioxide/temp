/*
    author  : PakinDioxide
    created : 01/04/2025 00:22
    task    : Astley
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    map <int, int> vis;
    int a = 0, b = 1;
    while (a < 2000) {
        int k = b;
        b = a+b;
        a = k;
        vis[a] = 1;
    }
    int n;
    cin >> n;
    if (n == 404) cout << "goodbye\n";
    else if (vis[n]) cout << "never\n";
    else cout << "gonna\n";
}