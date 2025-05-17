/*
    author  : PakinDioxide
    created : 04/05/2025 11:17
    task    : codecube_085
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    char s[100005];
    scanf("%s", &s);
    int n = strlen(s), mn = INT_MAX;
    int mp[26];
    for (int i = 1; i < n; i++) if (n % i == 0) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            memset(mp, 0, sizeof(mp));
            int mx = 0;
            for (int k = j; k < n; k += i) mp[s[k]-'a']++, mx = max(mx, mp[s[k]-'a']);
            cnt += n/i-mx;
        }
        mn = min(mn, cnt);
    }
    printf("%d\n", mn);
}