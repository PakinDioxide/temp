#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n], ans[n];
    stack <int> st;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), ans[i] = 0;
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) st.pop();
        if (!st.empty()) ans[i] = st.top() - i;
        st.push(i);
    }
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
}