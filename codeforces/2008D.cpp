#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    int a[n], b[n], cnt[n], vis[n];
    char s[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--, cnt[i] = vis[i] = 0;
    scanf("%s", &s);
    for (int i = 0; i < n; i++) b[i] = s[i] == '0' ? 0 : 1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int x = i, c = 0;
        vector <int> v;
        while (!vis[x]) {
            vis[x] = i+1;
            if (b[x] == 0) c++;
            v.push_back(x);
            x = a[x];
        }
        for (int j : v) cnt[j] = c;
    }
    for (int i = 0; i < n; i++) printf("%d ", cnt[i]);
    printf("\n");
} 

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}