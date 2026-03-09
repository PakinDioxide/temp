#include "game.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n;
int cnt[1505];

void initialize(int N) {
    n = N;
}

int hasEdge(int u, int v) {
    return (++cnt[u] == n-1 || ++cnt[v] == n-1);
}
