#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &k, &m);
    vector <pair <int, int>> v;
    int ok[n];
    for (int i = 0; i < n; i++) {
        ok[i] = 1;
        int s, f;
        scanf("%d %d", &s, &f);
        v.emplace_back(s, 1);
        v.emplace_back(f, 0);
    }
    sort(v.begin(), v.end());
    int c = 0;
    for (auto [x, y] : v) {
        if (!ok[x]) continue;
        if (y = 0) c++;
        else c--;
        if (c > k) {
            ok[x] = 0;
            c--;
        }
    }
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        if (ok[q-1]) printf("Y ");
        else printf("N ");
    }
}