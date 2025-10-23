#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int cnt = 0;
    char s[100005];
    fgets(s, 100005, stdin);
    for (int i = 0; i < 100000; i++) {
        if (s[i] == 0) break;
        if (s[i] >= '0' && s[i] <= '9') cnt += s[i] - '0';
        else if (s[i] >= 'A' && s[i] <= 'Z') cnt += s[i] - 'A';
        else if (s[i] >= 'a' && s[i] <= 'z') cnt -= s[i] - 'a';
    }
    cout << cnt;
}