/*
    author  : PakinDioxide
    created : 09/04/2025 20:57
    task    : 2sat
*/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void p(int k) {
    cout << k << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int x = 1;
    p(x);
    p(!x);
    p((!(x))|(!(x)));
    p((x|x));
}