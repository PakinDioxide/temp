#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, r = 1;
        cin >> a;

        for (int j = 2; j*j <= a; j++) {
            int c = 1;
            while (a % j == 0) {
                c++;
                a/=j;
            }
            r*=c;
        }

        if (a != 1) r*= 2;

        cout << r << "\n";
    }
}
