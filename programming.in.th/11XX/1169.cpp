#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack <char> st;
    int ans = 0;
    for (char x : s) {
        if (x == '(') st.push(x);
        else {
            if (!st.empty() && st.top() == '(') st.pop();
            else st.push(x);
        }
    }
    cout << st.size();
}