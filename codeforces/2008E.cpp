#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    int k = n % 2;
    if (n % 2 == 1) {
        s = " " + s;
        int pe[26][n+1], po[26][n+1], se[26][n+2], so[26][n+2];
        for (int i = 0; i < 26; i++) pe[i][0] = po[i][0] = se[i][n+1] = so[i][n+1] = 0;
        for (int i = 1; i <= n; i++) {
            for (char j = 'a'; j <= 'z'; j++) pe[j-'a'][i] = pe[j-'a'][i-1], po[j-'a'][i] = po[j-'a'][i-1];
            if (i % 2 == 0) {
                pe[s[i]-'a'][i]++;
            } else po[s[i]-'a'][i]++;
        }
        for (int i = n; i >= 1; i--) {
            for (char j = 'a'; j <= 'z'; j++) se[j-'a'][i] = se[j-'a'][i+1], so[j-'a'][i] = so[j-'a'][i+1];
            if (i % 2 == 0) {
                se[s[i]-'a'][i]++;
            } else so[s[i]-'a'][i]++;
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int mxe = 0, mxo = 0;
            for (char j = 'a'; j <= 'z'; j++) mxe = max(mxe, pe[j-'a'][i-1] + so[j-'a'][i+1]), mxo = max(mxo, po[j-'a'][i-1] + se[j-'a'][i+1]);
            mx = max(mx, mxe + mxo);
        }
        printf("%d\n", n - mx);
    } else {
        map <char, int> e, o;
        int mxe = 0, mxo = 0;
        for (int i = 0; i < n; i+=2) e[s[i]]++, mxe = max(mxe, e[s[i]]);
        for (int i = 1; i < n; i+=2) o[s[i]]++, mxo = max(mxo, o[s[i]]);
        printf("%d\n", k + n - mxe - mxo);
    }
    
} 

int32_t main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}