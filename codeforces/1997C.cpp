#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    scanf("%d", &n);
    char a[n];
    int cnt = 0;
    scanf("%s", &a);
    deque <int> q;
    for (int i = 0; i < n; i++) {
        if (q.empty() || a[i] == '(') q.push_back(i);
        else {
            cnt += i - q.front();
            q.pop_front();
        }
    }
    printf("%d\n", cnt);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}