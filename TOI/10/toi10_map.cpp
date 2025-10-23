#include <bits/stdc++.h>

using namespace std;

int adj[40005][4], a[405][405], vis[405][405], n, m, mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, mx = 0, my = 0, mmx = 405, mmy = 405;

void dfs(int x, int y) {
    vis[x][y] = 1;
    mx = max(x, mx); my = max(y, my); mmx = min(x, mmx); mmy = min(y, mmy);
    for (int l = 0; l < 4; l++) {
        int i = mov[l][0], j = mov[l][1];
        if (adj[a[x][y]][l] == 0 || vis[x+i][y+j]) continue;
        a[x+i][y+j] = adj[a[x][y]][l];
        dfs(x+i, y+j);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m*n-1; i++) {
        int a, b;
        char c;
        scanf("%d %c %d", &a, &c, &b);
        a++;
        b++;
        if (c == 'U') {
            adj[b][0] = a;
            adj[a][1] = b;
        } else {
            adj[b][2] = a;
            adj[a][3] = b;
        }
    }
    a[200][200] = 1;
    dfs(200, 200);
    for (int i = mmx; i <= mx; i++) {
        for (int j = mmy; j <= my; j++) printf("%d ", a[i][j]-1);
        printf("\n");
    }
}