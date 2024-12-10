#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    for (int s = min(a.size(), b.size()); s > 0; s--) {
        for (int i = 0; i <= a.size()-s; i++) {
            for (int j = 0; j <= b.size()-s; j++) {
                if (a[i] != b[j]) continue;
                string x = a.substr(i, s), y = b.substr(j, s);
                if (x == y) {
                    cout << x;
                    return 0;
                }
            }
        }
    }
}