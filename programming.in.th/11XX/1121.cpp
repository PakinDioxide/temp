#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stack <char> st;
        bool ok = true;

        for (auto j : s) {
            if (j == '(' || j == '[' || j == '{') {
                st.push(j);
            } else {
                char inv;

                if (j == ')') inv = '(';
                else if (j == ']') inv = '[';
                else inv = '{';

                if (!st.empty() && st.top() == inv) {
                    st.pop();
                } else {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok || !st.empty()) cout << "no\n";
        else cout << "yes\n";
    }
}
