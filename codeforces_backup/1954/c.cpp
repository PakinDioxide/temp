#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int same = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i == same) {
            if (a[i] < b[i]) {
                char temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            } else if (a[i] == b[i]) {
                same++;
            }
        } else {
            if (a[i] > b[i]) {
                char temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
        }
    }
    cout << a << '\n' << b << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}