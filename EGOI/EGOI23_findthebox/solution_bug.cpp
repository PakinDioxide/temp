#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    if (n == 1) {
        string s = "";
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        int p, q; cin >> p >> q;
        cout << "! " << p << ' ' << q+1 << endl;
        exit(0);
    } else if (m == 1) {
        string s = "";
        for (int i = 0; i < n; i++) s += 'v';
        cout << "? " << s << endl;
        int p, q; cin >> p >> q;
        cout << "! " << p+1 << ' ' << q << endl;
        exit(0);
    } else if (n == 2 && m == 2) {
        string s = "";
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        int p, q; cin >> p >> q;
        if (q == 0) { cout << "! " << p << ' ' << q+1 << endl; exit(0); }
        s = "";
        for (int i = 0; i < m; i++) s += 'v';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (p == 0) cout << "! " << p+1 << ' ' << q << endl;
        else cout << "! 1 1" << endl;
    } else if (m % 2 == 0) {
        int x = n/2-1, p, q;
        string s = "";
        for (int i = 0; i < x; i++) s += "v";
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (p != x) {
            cout << "! " << p+1 << ' ' << 0 << endl;
            exit(0);
        }
        if (q < m-1) {
            cout << "! " << p << ' ' << q+1 << endl;
            exit(0);
        }
        x++;
        s = "";
        for (int i = 0; i < x; i++) s += "v";
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (p != x) {
            cout << "! " << p+1 << ' ' << 0 << endl;
            exit(0);
        }
        if (q < m-1) {
            cout << "! " << p << ' ' << q+1 << endl;
            exit(0);
        }
        s = "";
        for (int i = 0; i < n; i++) s += 'v';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (p < n-1) {
            cout << "! " << p+1 << ' ' << 0 << endl;
            exit(0);
        }
        s = "";
        x--;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < x; j++) s += "^v"[i%2];
            s += '>';
        }
        for (int i = m; i >= 1; i--) {
            for (int j = 0; j < x; j++) s += "v^"[i%2];
            s += '<';
        }
        s += '^';
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (q < m-1) {
            cout << "! " << p << ' ' << q+1 << endl;
            exit(0);
        }
        for (int i = 0; i < n - n/2; i++) s = "v" + s;
        for (int i = 0; i <= m; i++) s.pop_back();
        for (int i = 0; i <= x; i++) s += "v";
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (q < m-1) {
            cout << "! " << p << ' ' << q+1 << endl;
            exit(0);
        }
    } else {
        int x = n/2, p, q;
        string s = "";
        for (int i = 0; i < x; i++) s += "v";
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (p != x) {
            cout << "! " << p+1 << ' ' << 0 << endl;
            exit(0);
        }
        if (q < m-1) {
            cout << "! " << p << ' ' << q+1 << endl;
            exit(0);
        }
        x++;
        s = "";
        for (int i = 0; i < x; i++) s += "v";
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (p != x) {
            cout << "! " << p+1 << ' ' << 0 << endl;
            exit(0);
        }
        if (q < m-1) {
            cout << "! " << p << ' ' << q+1 << endl;
            exit(0);
        }
        s = "";
        for (int i = 0; i < n; i++) s += 'v';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (p < n-1) {
            cout << "! " << p+1 << ' ' << 0 << endl;
            exit(0);
        }
        s = "";
        x--;
        for (int i = 0; i < x; i++) s += 'v';
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < x; j++) s += "v^"[i%2];
            s += '>';
        }
        for (int i = m; i >= 1; i--) {
            for (int j = 0; j < x; j++) s += "^v"[i%2];
            s += '<';
        }
        for (int i = 0; i <= x; i++) s += '^';
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (q < m-1) {
            cout << "! " << p << ' ' << q+1 << endl;
            exit(0);
        }
        for (int i = 0; i < n; i++) s = "v" + s;
        for (int i = 0; i <= m+x; i++) s.pop_back();
        // for (int i = 0; i <= x; i++) s += "v";
        s += 'v';
        for (int i = 0; i < m; i++) s += '>';
        cout << "? " << s << endl;
        cin >> p >> q;
        if (q < m-1) {
            cout << "! " << p << ' ' << q+1 << endl;
            exit(0);
        }
    }
}
