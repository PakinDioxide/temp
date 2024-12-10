#include <bits/stdc++.h>

using namespace std;

int mov[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}, n, m, dis[105][105];
char a[105][105];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf(" %c", &a[i][j]);
    queue <pair <int, int>> q;
    q.emplace(0, 0);
    dis[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int l = 0; l < 4; l++) {
            int i = mov[l][0], j = mov[l][1];
            if (x+i < 0 || x+i == n || y+j < 0 || y+j == m) continue;
            else if (i == -1 && (a[x+i][y+j] == 'R' || a[x+i][y+j] == 'N')) continue;
            else if (i == 1 && (a[x][y] == 'R' || a[x][y] == 'N')) continue;
            else if (j == -1 && (a[x+i][y+j] == 'D' || a[x+i][y+j] == 'N')) continue;
            else if (j == 1 && (a[x][y] == 'D' || a[x][y] == 'N')) continue;
            if (dis[x+i][y+j] == 0) {dis[x+i][y+j] = dis[x][y] + 1; q.emplace(x+i, y+j);}
            else if (dis[x+i][y+j] == dis[x][y]+1) {
                printf("%d\n%d %d", dis[x+i][y+j], x+i+1, y+j+1);
                return 0;
            } 
        }
    }
}