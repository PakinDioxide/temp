#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x - a[i-1];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt += (x <= a[i]);
    }
    cout << cnt << '\n';
}

/*
60 10 
85 29 57 9 1
*/