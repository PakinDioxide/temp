#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    string s, ss;
    cin >> n >> ss;
    map <char, char> t;
    stack <char> st;
    for (char i : ss) {
        if (i == ')' && !st.empty() && st.top() == '(') st.pop();
        else if (i == ']' && !st.empty() && st.top() == '[') st.pop();
        else st.push(i);
    }
    while (!st.empty()) s += st.top(), st.pop();
    s+=' ';
    reverse(s.begin(), s.end());
    n = s.size()-1;
    ll dp[n+1], mod = 1e9+7;
    for (int i = 1; i <= n; i++) {
        if (i % 2) dp[i] = dp[i-1];
        
    }
}
