/*
    author  : PakinDioxide
    created : 04/05/2025 19:26
    task    : D2_B
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 1e5+5;

ll n, l[mxN], r[mxN], x[mxN];
vector <int> adj[mxN];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1, e; i <= n; i++) {
        cin >> l[i] >> r[i] >> x[i];
        adj[e].emplace_back(i);
    }
    
}