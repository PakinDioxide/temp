#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    scanf("%d", &n);
    vector <int> a;
    map <int, int> c;
    for (int i = 0; i < n; i++) {scanf("%d", &x); if (!c[x]) a.push_back(x); c[x] = 1;}
    // sort(a.begin(), a.end());
    // int act = 0;
    // for (int i = 0; i < a.size(); i++) {
    //     if (a[i] == 0) continue;
    //     x = a[i] - ((a.size()-i) % 2 == 0);
    //     if (x == 0) x++;
    //     for (int j = i; j < a.size(); j++) {a[j] -= x; printf("%d ", a[j]);}
    //     printf("\n");
    //     if (a[i] > 0) i--;
    //     act++;
    // }
    if (a.size() & 1) printf("Alice\n");
    else printf("Bob\n");
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) solve();
}