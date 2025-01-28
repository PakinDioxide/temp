#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) cnt += (s[i] < s[j]);
    cout << cnt << '\n';
}