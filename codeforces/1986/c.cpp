#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        char s[n+10], c[m+10];
        int a[m+10];
        scanf("%s", &s);
        for (int i = 0; i < m; i++) scanf("%d", &a[i]);
        scanf("%s", &c);
        sort(a, a+m);
        sort(c, c+m);
        int l = 0, r = m-1;
        char c2[m+10];
        for (int i = 0; i < m; i++) {
            if (i+1 >= m || a[i] != a[i+1]) c2[i] = c[l], l++;
            else c2[i] = c[r], r--;
        }
        for (int i = 0; i < m; i++) {
            s[a[i]-1] = c2[i];
        }
        printf("%s\n", s);
    }
}