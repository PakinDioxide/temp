#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    if (r >= g+b) {
        for (int i = 1; ; i++) {
            if (i % 2 == 1) {
                if (r == 0) break;
                cout << "R";
                r--;
            } else {
                if (g > 0) cout << "G", g--;
                else if (b > 0) cout << "B", b--;
                else break;
            }
        }
        cout << '\n';
        return;
    }
    if (g >= r+b) {
        for (int i = 1; ; i++) {
            if (i % 2 == 1) {
                if (g == 0) break;
                cout << "G";
                g--;
            } else {
                if (r > 0) cout << "R", r--;
                else if (b > 0) cout << "B", b--;
                else break;
            }
        }
        cout << '\n';
        return;
    }
    if (b >= g+r) {
        for (int i = 1; ; i++) {
            if (i % 2 == 1) {
                if (b == 0) break;
                cout << "B";
                b--;
            } else {
                if (g > 0) cout << "G", g--;
                else if (r > 0) cout << "R", r--;
                else break;
            }
        }
        cout << '\n';
        return;
    }
    int k = floor((r+b+g)/2.0), K = ceil((r+b+g)/2.0);
    vector <int> a = {r, g, b};
    vector <char> ch = {'R', 'G', 'B'};
    vector <pair <int, char>> idk = {{r, 'R'}, {g, 'G'}, {b, 'B'}};
    sort(idk.begin(), idk.end());
    for (int i = 0; i < 3; i++) a[i] = idk[i].first, ch[i] = idk[i].second;
    int T = r+b+g;
    do {
        // for (auto &e : a) cout << e << ' '; cout << '\n';
        // continue;
        // cout << 2*(K-a[0]) - 1 << ' ' << T - (T % 2) - 2*(a[1] - (K-a[0]) - 1) << '\n';
        if ((a[1] - (K-a[0]) != 0) && 2*(K-a[0]) - 1 + 4 >= T - (T % 2) - 2*(a[1] - (K-a[0]) - 1)) continue;
        for (int i = 0; i < T; i++) {
            if (i % 2 == 0) {
                if (i/2 < (K-a[0])) cout << ch[1];
                else cout << ch[0];
            } else {
                if (i/2 < a[2]) cout << ch[2];
                else cout << ch[1];
            }
        }
        cout << '\n';
        return;
    } while (next_permutation(a.begin(), a.end()) && next_permutation(ch.begin(), ch.end()));
    assert(0);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

