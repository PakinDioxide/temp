#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    long long n, ans = 0;

    cin >> n;

    string a, b;

    cin >> a >> b;

    for (long long i = 0; i < n-1; i++) {
        if (a[i] != b[i] && a[i+1] == b[i+1]) ans++;
    }

    if (a[n-1] != b[n-1]) ans++;

    freopen("breedflip.out", "w", stdout);

    cout << ans;
}
