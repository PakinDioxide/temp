#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int ok = 0;
    for (int i = 0; i < s.size(); i++) {
        printf("%c", s[i]);
        if ((s[i] == s[i+1] || i == s.size()-1) && !ok) printf("%c", s[i] == 'a' ? 'z' : 'a'), ok = 1;
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}