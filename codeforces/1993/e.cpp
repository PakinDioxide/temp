#include <bits/stdc++.h>

using namespace std;

#define int long long

map <tuple <int, int, int, int>, int> vis, memo;
map <int, int> pp;

void solve() {
    int n, w, h, k, c = 0, x = 0, y = 0, p = 0, q = 0;
    scanf("%lld %lld %lld %lld", &n, &k, &w, &h);
    char s[n];
    pp[0] = 0;
    scanf("%s", &s);
    while (k--) {
        for (int i = 0; i < n; i++) {
            if ((s[i] == 'U' && !p) || (s[i] == 'D' && p)) {
                if (y + 1 > h) y--, p = !p;
                else y++;
            } else if ((s[i] == 'D' && !p) || (s[i] == 'U' && p)) {
                if (y - 1 < 0) y++, p = !p;
                else y--;
            } else if ((s[i] == 'L' && !q) || (s[i] == 'R' && q)) {
                if (x - 1 < 0) x++, q = !q;
                else x--;
            } else if ((s[i] == 'R' && !q) || (s[i] == 'L' && q)) {
                if (x + 1 > w) x--, q = !q;
                else x++;
            }
            if (x == 0 && y == 0) c++;
            // printf("%d %d\n", x, y);
        }
        pp[k+1] = c;
        if (vis[{p, q, x, y}]) {
            int t = memo[{p, q, x, y}] - k;
            c += (k/t)*(pp[k+1] - pp[memo[{p, q, x, y}]]) + (pp[memo[{p, q, x, y}] + (k % t)] - pp[memo[{p, q, x, y}]]);
            break;
        }
        if (!vis[{p, q, x, y}]) vis[{p, q, x, y}] = 1, memo[{p, q, x, y}] = k;
    }
    printf("%lld\n", c);
}

int32_t main() {
    int t;
    scanf("%lld", &t);
    while (t--) solve();
}