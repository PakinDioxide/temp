#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, ok = 1;
        scanf("%d", &n);
        char a[n], b[n];
        scanf("%s %s", &a, &b);
        for (int i = 0; i < n; i++) {
            if (a[i] == '0' && b[i] == '1') {ok = 0; break;}
            if (a[i] == '1') break;
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
}