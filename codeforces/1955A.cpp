#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (a&1)*b + min((a-(a&1))*b, (a/2)*c) << '\n';
    }
}