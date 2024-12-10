#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);

    long long siz[3], hav[3];

    for (int i = 0; i < 3; i++) cin >> siz[i] >> hav[i];

    for (int i = 0; i < 33; i++) {
        hav[1] += hav[0];
        hav[0] = max(hav[1] - siz[1], (long long) 0);
        hav[1] = min(hav[1], siz[1]);
        hav[2] += hav[1];
        hav[1] = max(hav[2] - siz[2], (long long) 0);
        hav[2] = min(hav[2], siz[2]);
        hav[0] += hav[2];
        hav[2] = max(hav[0] - siz[0], (long long) 0);
        hav[0] = min(hav[0], siz[0]);
    }
    hav[1] += hav[0];
    hav[0] = max(hav[1] - siz[1], (long long) 0);
    hav[1] = min(hav[1], siz[1]);
    
    freopen("mixmilk.out", "w", stdout);

    cout << hav[0] << "\n" << hav[1] << "\n" << hav[2];
}
