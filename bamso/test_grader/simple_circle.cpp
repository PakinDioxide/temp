#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 2*n+1; i++) {
        for (int j = 1; j <= 2*n+1; j++) {
            int x = abs(n-i+1), y = abs(n-j+1);
            if (abs(x*x + y*y - n*n) <= n) cout << "x ";
            else cout << ". ";
        }
        cout << '\n';
    }
}