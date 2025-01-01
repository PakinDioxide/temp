#include <bits/stdc++.h>

using namespace std;

string getstr(int i, int j) {
    string t = "";
    t += 'a' + i, t += 'a' + j, t += 'a' + j;
    return t;
}

int main() {
    int n, f;
    cin >> n >> f;
    string s;
    cin >> s;
    s = " " + s;
    set <string> ans;
    int cnt[n+2][26][26], ctt[n+2][26][26];
    for (int i = 0; i <= n+1; i++) for (int j = 0; j < 26; j++) for (int k = 0; k < 26; k++) cnt[i][j][k] = ctt[i][j][k] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) for (int k = 0; k < 26; k++) cnt[i][j][k] = cnt[i-1][j][k];
        if (i > 2 && s[i-2] != s[i-1] && s[i-1] == s[i]) cnt[i][s[i-2]-'a'][s[i-1]-'a']++;
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < 26; j++) for (int k = 0; k < 26; k++) ctt[i][j][k] = ctt[i+1][j][k];
        if (i <= n-2 && s[i] != s[i+1] && s[i+1] == s[i+2]) ctt[i][s[i]-'a'][s[i+1]-'a']++;
    }
    for (int j = 0; j < 26; j++) for (int k = 0; k < 26; k++) if (cnt[n][j][k] >= f) ans.insert(getstr(j, k));
    for (char k = 'a'; k <= 'z'; k++) {
        for (int i = 1; i <= n; i++) {
            if (k == s[i]) continue;
            if (i <= n-2) {
                if (k != s[i+1] && s[i+1] == s[i+2] && cnt[i-1][k-'a'][s[i+1]-'a'] + ctt[i+3][k-'a'][s[i+1]-'a'] + 1 >= f) ans.insert(getstr(k-'a', s[i+1]-'a'));
            }
            if (i > 1 && i < n) {
                if (s[i-1] != k && k == s[i+1] && cnt[i-2][s[i-1]-'a'][k-'a'] + ctt[i+2][s[i-1]-'a'][k-'a'] + 1 >= f) ans.insert(getstr(s[i-1]-'a', k-'a'));
            }
            if (i > 2) {
                if (s[i-2] != s[i-1] && s[i-1] == k && cnt[i-3][s[i-2]-'a'][s[i-1]-'a'] + ctt[i+1][s[i-2]-'a'][s[i-1]-'a'] + 1 >= f) ans.insert(getstr(s[i-2]-'a', s[i-1]-'a'));
            }
        }
    }
    cout << ans.size() << '\n';
    for (string t : ans) cout << t << '\n';
}