#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);
        int a[n], c = 0, sum = 0;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        deque <int> q;
        for (int i = 0; i < n; i++) {
            int k = a[i];
            sum += k;
            q.push_back(k);
            if (sum >= l && sum <= r) {sum = 0; c++; while (!q.empty()) q.pop_back();}
            else {
                while (sum > r) {
                    sum -= q.front();
                    q.pop_front();
                }
                if (sum >= l) {sum = 0; c++; while (!q.empty()) q.pop_back();}
            }
        }
        printf("%d\n", c);
    }
}