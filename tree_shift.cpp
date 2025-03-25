/*
    author  : PakinDioxide
    created : 19/03/2025 01:52
    task    : tree_shift
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    auto fl = [&] (int x) { for (int i = 0; 1; i++) if (x >= (1 << i) && x < (1 << (i+1))) return i+1; };
    int shf[20], shf2[20];
    memset(shf, 0, sizeof(shf));
    memset(shf2, 0, sizeof(shf2));
    // cout << '\n';
    while (q--) {
        int t, x, k;
        cin >> t;
        if (t == 1) {
            cin >> x >> k;
            k=-k;
            int lv = fl(x), sz = (1 << (lv-1));
            shf[lv] += (k%sz+sz)%sz, shf[lv] %= sz;
            k=-k;
            shf2[lv] += (k%sz+sz)%sz, shf2[lv] %= sz;
            // cout << x << ' ' << lv << ' ' << shf[lv] << ' ' << sz << '\n';
        } else if (t == 2) {
            cin >> x >> k;
            int lv = fl(x), sz = (1 << (lv-1));
            shf2[lv] += (k%sz+sz)%sz, shf2[lv] %= sz;
        } else {
            cin >> x;
            int lv = fl(x);
            while (x != 1) {
                cout << x << ' ';
                int sz = (1 << (lv-1));
                x = ((x - sz) + shf2[lv]) % sz + sz;
                // cout << x << " | ";
                x /= 2;
                lv--;
                sz = (1 << (lv-1));
                // cout << sz << " | ";
                x = ((x - sz) + shf[lv]) % sz + sz;
            }
            cout << "1\n";
        }
    }
}

/*
     1
  2     3
4   5 6   7
*/