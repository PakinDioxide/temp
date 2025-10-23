#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    stack <int> op, n;
    for (char x : s) {
        if (x == '[') op.push(0);
        else if (x == ']') {
            while (op.top() != 0) {
                int a = n.top(); n.pop();
                int b = n.top(); n.pop();
                int o = op.top(); op.pop();
                double sum = a+b;
                if (o == 1) sum = sum*104/100;
                else if (o == 2) sum = sum*108/100;
                else sum = sum*116/100;
                n.push((int) sum);
            }
            op.pop();
        } else if (x >= 'A' && x <= 'Z') n.push(20);
        else {
            while (!op.empty() && x - '0' <= op.top()) {
                int a = n.top(); n.pop();
                int b = n.top(); n.pop();
                int o = op.top(); op.pop();
                double sum = a+b;
                if (o == 1) sum = sum*104/100;
                else if (o == 2) sum = sum*108/100;
                else sum = sum*116/100;
                n.push((int) sum);
            }
            op.push(x - '0');
        }
    }
    while (!op.empty()) {
        int a = n.top(); n.pop();
        int b = n.top(); n.pop();
        int o = op.top(); op.pop();
        double sum = a+b;
        if (o == 1) sum = sum*104/100;
        else if (o == 2) sum = sum*108/100;
        else sum = sum*116/100;
        n.push((int) sum);
    }
    cout << n.top();
}