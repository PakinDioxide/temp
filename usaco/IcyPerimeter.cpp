#include <bits/stdc++.h>

using namespace std;

int n;

vector <string> v;
vector <vector <bool>> al;

int per = 0;

int area(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < n && al[i][j]) return 0;
    if (i < 0 || i >= n || j < 0 || j >= n || v[i][j] != '#') {
        per++;
        return 0;
    }

    al[i][j] = true;

    return 1 + area(i+1, j) + area(i-1, j) + area(i, j+1) + area(i, j-1);
}

int main() {
    freopen("perimeter.in", "r", stdin);
    cin >> n;

    v.resize(n);
    al.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        al[i].resize(n);
    }

    int a = 0, pe = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!al[i][j] && v[i][j]=='#') {
                per = 0;
                int aa = area(i, j);
                if (a < aa) {
                    a = aa;
                    pe = per;
                } else if (a == aa && per < pe) {
                    a = aa;
                    pe = per;
                }
            }
        }
    }

    freopen("perimeter.out", "w", stdout);

    cout << a << " " << pe;
}
