    #include <bits/stdc++.h>

    using namespace std;

    void solve() {
        int l, r;
        scanf("%d %d", &l, &r);
        int rng = r - l + 1, cnt = 0;
        for (int i = l; i <= r; i += ++cnt);
        printf("%d\n", cnt);
    } 

    int main() {
        int t;
        scanf("%d", &t);
        while (t--) solve();
    }