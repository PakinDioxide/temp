#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n, a[26];
    cin >> n;
    memset(a, 0, sizeof(a));
    while (n--) {
        string x, y;
        cin >> x >> y;
        int b[26], c[26];
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        for (auto e : x) b[e-'a']++;
        for (auto e : y) c[e-'a']++;
        for (int i = 0; i < 26; i++) a[i] += max(b[i], c[i]);
    }
    for (int i = 0; i < 26; i++) cout << a[i] << '\n';
}