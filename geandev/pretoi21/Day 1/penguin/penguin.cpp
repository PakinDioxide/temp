#include "penguin.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <pair <int, int>> v;
vector <int> T;
int N, vis[15005];
map <pair <int, int>, int> mp;

// SUB 3
// void solve(int l, int r) {
//     if (l > r) return;
//     if (l == r) {v.emplace_back(0, l); return;}
//     int x = l + (r-l)/2;
//     if (ask(0, 0, l, x)) solve(l, x);
//     if (ask(0, 0, x+1, r)) solve(x+1, r);
// }

// SUB 4
void solve(int l, int r) {
    if (l > r) return;
    if (l == r) {T.emplace_back(l); return;}
    int x = l + (r-l)/2;
    if (ask(0, N-1, l, x)) solve(l, x);
    if (ask(0, N-1, x+1, r)) solve(x+1, r);
}

// SUB 5
void solve2(int l, int r, int u) {
    if (l > r) return;
    if (l == r) {if (!mp[{u, l}]) mp[{u, l}] = mp[{l, u}] = 1, v.emplace_back(u, l); return;}
    int x = l + (r-l)/2;
    if (ask(u, u, l, x)) solve2(l, x, u);
    if (ask(u, u, x+1, r)) solve2(x+1, r, u);
}

vector<std::pair<int, int>> find_couples(int n) {
    N = n;
    // SUB 1
    // for (int i = 0; i < n; i++) {
    //     for (int j = i+1; j < n; j++) if (ask(i, i, j, j)) v.emplace_back(i, j);
    // }

    // SUB 2
    // int l = 0, r = n-1, u = 0, V = 0;
    // while (l <= r) {
    //     int x = l + (r-l)/2;
    //     if (ask(l, x, 0, n-1)) u = x, r = x-1;
    //     else l = x+1;
    // }
    // l = 0, r = n-1;
    // while (l <= r) {
    //     int x = l + (r-l)/2;
    //     if (ask(u, u, l, x)) V = x, r = x-1;
    //     else l = x+1;
    // }
    // v.emplace_back(u, V);


    // SUB 3
    // solve(0, n-1);

    // SUB 4
    // solve(0, n-1);
    // sort(T.begin(), T.end());
    // for (auto &e : T) {
    //     if (vis[e]) continue;
    //     int l = e+1, r = n-1, V = -1;
    //     while (l <= r) {
    //         int x = l + (r-l)/2;
    //         if (ask(e, e, l, x)) V = x, r = x-1;
    //         else l = x+1;
    //     }
    //     v.emplace_back(e, V);
    //     vis[V] = 1;
    // }

    // SUB 5
    solve(0, n-1);
    sort(T.begin(), T.end());
    for (int i = 0; i < T.size()-1; i++) solve2(T[i]+1, n-1, T[i]);
    return v;
}