#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool ask(string s) { cout << "? " << s << endl; int x; cin >> x; return x; }

void solve() {
    int N; cin >> N;
    string s = "";
    int i;
    for (i = 0; i < N; i++) {
        if (ask(s + '0')) s += '0';
        else if (ask(s + '1')) s += '1';
        else break;
    }
    for (; i < N; i++) {
        if (ask("0" + s)) s = "0" + s;
        else s = "1" + s;
    }
    cout << "! " << s << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}

