#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack <pair<int, int>> s;
    s.push({0, 0});

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        while (!s.empty() && s.top().first >= a) s.pop();
        cout << s.top().second << ' ';
        s.push({a, i});
    }
}
