#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 0; i < 2*x; i++) {
            for (int j = 0; j < 2*x; j++) {
                if (((i/2)%2 == 0 && (j/2)%2 == 0) || ((i/2)%2 == 1 && (j/2)%2 == 1)) cout << '#';
                else cout << '.';
            }
            cout << '\n';
        }
    }
}