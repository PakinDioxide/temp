#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

bool solve() {
    string s;
    cin >> s;
    int non = 0, a = 0, b = 0, c = 0;
    for (char i : s) {
        if (i > '3' || i == '1') non += i - '0', non %= 9;
        else if (i == '2') b++;
        else if (i == '3') c++;
    }
    for (int i = 0; i <= b; i++) {
        int k = (9 - ((non + 4*i + 2*(b-i))%9))%9;
        if (k % 3 == 0 && k/3 <= c) return 1; 
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) cout << (solve() ? "YES\n" : "NO\n");
}