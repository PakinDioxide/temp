#include <bits/stdc++.h>

using namespace std;

string str;

struct Node {
    string val;
    vector <struct Node*> child;
};

using pnode = struct Node*;

pnode build(string s) {
    // cerr << s << '\n';
    pnode xnode = new Node;
    xnode -> val = s;
    if (s.size() == 1) return xnode;
    int ok = 0, open = 0, l = 0;
    for (char i : s) {
        if (i == '(') open++;
        else if (i == ')') open--;
        if (i == '+' && open == 0) {ok = 1; break;}
    }
    open = 0, l = 0;
    if (ok) {
        for (int r = 0; r < s.size(); r++) {
            char i = s[r];
            if (i == '(') open++;
            else if (i == ')') open--;
            if (i == '+' && open == 0) {
                string temp = s.substr(l, r-l);
                (xnode -> child).push_back(build(temp));
                l = r+1;
            }
        }
        string temp = s.substr(l, s.size()-l+1);
        (xnode -> child).push_back(build(temp));
        return xnode;
    }
    ok = 0, open = 0, l = 0;
    for (char i : s) {
        if (i == '(') open++;
        else if (i == ')') open--;
        if (i == '*' && open == 0) {ok = 1; break;}
    }
    open = 0, l = 0;
    if (ok) {
        for (int r = 0; r < s.size(); r++) {
            char i = s[r];
            if (i == '(') open++;
            else if (i == ')') open--;
            if (i == '*' && open == 0) {
                string temp = s.substr(l, r-l);
                
                (xnode -> child).push_back(build(temp));
                l = r+1;
            }
        }
        string temp = s.substr(l, s.size()-l+1);
        (xnode -> child).push_back(build(temp));
        return xnode;
    }
    ok = 0, open = 0, l = 0;
    for (char i : s) {
        if (i == '(') open++;
        else if (i == ')') open--;
        if (i == '^' && open == 0) {ok = 1; break;}
    }
    open = 0, l = 0;
    if (ok) {
        for (int r = 0; r < s.size(); r++) {
            char i = s[r];
            if (i == '(') open++;
            else if (i == ')') open--;
            if (i == '^' && open == 0) {
                string temp = s.substr(l, r-l);
                (xnode -> child).push_back(build(temp));
                l = r+1;
            }
        }
        string temp = s.substr(l, s.size()-l+1);
        (xnode -> child).push_back(build(temp));
        return xnode;
    }
    if (s.size() > 1 && s[0] == '(' && s[s.size() - 1] == ')') s.erase(s.begin()), s.erase(s.end() - 1);
    (xnode -> child).push_back(build(s));
    return xnode;
}

int main() {
    cin >> str;
    int q;
    scanf("%d", &q);
    pnode root = build(str);
    while (q--) {
        int cnt = 0, x, ok = 1;
        vector <int> t;
        pnode curr = root;
        while (1) {
            scanf("%d", &x);
            if (x == 0) break;
            cnt++;
            t.push_back(x);
            if (x == 1 && (curr -> val).size() == 1) continue;
            else if (x > (curr -> child).size()) ok = 0;
            if (ok) {
                x--;
                curr = (curr -> child)[x];
            }
        }
        for (int i = cnt-1; i >= 0; i--) printf("op(%d,", t[i]);
        printf("p");
        for (int i = 0; i < cnt; i++) printf(")");
        printf("=");
        cout << (ok ? curr -> val : "null") << '\n';
    }
}