#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    /*
    if (n == 1) {
        string s = "";
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        int p, q; cin >> p >> q;
        cout << "! " << p << ' ' << q+1 << endl;
        exit(0);
    } else if (m == 1) {
        string s = "";
        for (int i = 0; i < m; i++) s += 'v';
        cout << "? " << s << endl;
        int p, q; cin >> p >> q;
        cout << "! " << p+1 << ' ' << q << endl;
        exit(0);
    }
    */
    string s = "";
    for (int i = 0; i <= n; i++) s += 'v';
    for (int i = 0; i < m; i++) {
        cout << "? " << s << endl;
        int p, q; cin >> p >> q;
        if (q != i) { cout << "! " << 0 << ' ' << i << endl; exit(0); }
        else if (p < n-1) { cout << "! " << p+1 << ' ' << i << endl; exit(0); }
        s = ">" + s;
    }
}
