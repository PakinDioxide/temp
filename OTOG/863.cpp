#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    string a[n+1], s;
    deque <int> l, r;
    for (int i = 1; i <= n; i++) cin >> a[i], r.push_back(i);
    cin >> s;
    while (l.size() + r.size() > 1) {
        cin >> s;
        if (s == "SHIFT") {
            l.push_back(r.front());
            r.pop_front();
        } else if (s == "RIGHT") {
            l.pop_back();
        } else {
            r.pop_front();
            r.push_front(l.back()), l.pop_back();
        }
    }
    if (l.empty()) cout << a[r[0]] << '\n';
    else cout << a[l[0]] << '\n';
}