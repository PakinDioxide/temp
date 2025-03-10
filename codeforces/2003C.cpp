#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    char s[n], ans[n+1], k = 0;
    scanf("%s", &s);
    vector <int> cnt(26);
    for (int i = 0; i < n; i++) cnt[s[i]-'a']++;
    for (int i = 0; i < n; i++) {
        while (cnt[k] == 0) k++, k %= 26;
        ans[i] = k+'a';
        cnt[k]--;
        k++;
        k %= 26;
    }
    ans[n] = 0;
    printf("%s\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}