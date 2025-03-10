#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, cnt = 0;
        scanf("%d", &n);
        char a[n];
        scanf("%s", &a);
        for (int i = 0; i < n; i++) if (a[i] == 'U') cnt++;
        if (cnt&1) printf("YES\n");
        else printf("NO\n");
    }
}