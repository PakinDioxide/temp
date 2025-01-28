#include <bits/stdc++.h>
#define ll long long

using namespace std;

string x, xx;

int cmp(deque <char> &s) {
    for (int i = 0; i < x.size(); i++) {
        if (s[i] != x[i]) return 0;
    }
    return 1;
}

void solve(string s) {
    int n = s.size(), m = x.size(), dl = 0;
    deque <char> cur;
    for (int i = 0; i < m-1 && i < n-1; i++) cur.push_back(s[i]);
    for (int i = m-1; i < n; i++) {
        cur.push_back(s[i]);
        if (cur.size() > m) cur.pop_front();
        dl--;
        if (dl > 0) continue;
        if (cmp(cur)) {
            dl = m;
            for (int j = i-m+1; j <= i; j++) s[j] = xx[j-(i-m+1)];
            if (m != xx.size()) s.insert(s.begin() + i+1, xx.back()), i++, n++;
        }
    }
    cout << s << '\n';
}

int main() {
    int t;
    cin >> t;
    vector <string> s(t);
    for (auto &e : s) cin >> e;
    cin >> x;
    xx = to_string(stoi(x) + 1);
    for (auto e : s) solve(e);
}