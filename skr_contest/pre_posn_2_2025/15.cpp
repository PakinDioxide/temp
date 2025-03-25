/*
    author  : PakinDioxide
    created : 17/03/2025 19:59
    task    : 15
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int cnt[n+1][26], ccnt[n];
    memset(cnt, 0, sizeof(cnt));
    memset(ccnt, 0, sizeof(ccnt));
    for (int i = 0; i <= n; i++) {
        string s;
        cin >> s;
        for (auto &e : s) cnt[i][e-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        vector <int> w;
        int k = cnt[n][i];
        for (int j = 0; j < n; j++) {
            w.push_back(-cnt[j][i]);
            if (ccnt[])
        }
    }
}