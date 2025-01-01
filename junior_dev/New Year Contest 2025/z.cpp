// PakinDioxide - recursive
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, kkkkkk = 0;
    cin >> n;
    if(n==1) cout<<"1", kkkkkk = 1;
    if(n==2||n==3) cout<<"-1";
    else if (n==4) cout<<"1 3 4 2\n4 2 1 3\n2 4 3 1\n3 1 2 4", kkkkkk = 1;
    else if (n % 12 == 1 || n % 12 == 5 || n % 12 == 7 || n % 12 == 11) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << ((3*n*i+j)%n+1) << ' ';
            cout << '\n';
        }
        kkkkkk = 1;
    }
    if (kkkkkk) return 0;
    int a[n+1][n+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = 0;
    for (int i = 1; i <= n; i++) a[i][i] = i;
    for (int i = 1; i <= n; i++) a[i][n-i+1] = (2 + (n-i))%n + 1;
    for (int i = 1; i <= n; i++) {for (int j = 1; j <= n; j++) cout << a[i][j] << ' '; cout << '\n';}
}