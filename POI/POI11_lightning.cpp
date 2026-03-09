#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mxN = 5e5+5;

int n;
double h[mxN];

double itc(int j, int k) {
    double A = h[k] - h[j];
    double B = (k-j) / (2 * A) + A / 2;
    return B * B + j;
}

void solve(vector <int> &dp) {
    deque <int> q;
    int sz = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || h[i] > h[q.back()]) {
            while ((sz && h[i] >= h[q.back()] + ceil(sqrt(i - q.back()))) || (sz >= 2 && itc(q[sz-2], q[sz-1]) > itc(q[sz-1], i))) sz--, q.pop_back();
            q.emplace_back(i);
            sz++;
        }
        while (sz >= 2 && itc(q[0], q[1]) < i) q.pop_front(), sz--;
        dp[i] = h[q[0]] + ceil(sqrt(i - q[0]));
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector <int> dp1(n+1), dp2(n+1);
    solve(dp1);
    for (int i = 1; i <= n/2; i++) swap(h[i], h[n-i+1]);
    solve(dp2);
    for (int i = 1; i <= n; i++) cout << (int) (max(dp1[i], dp2[n-i+1]) - h[n-i+1]) << '\n';
}

/*
what if dp from both side, min height if cover 1 to i-1 and i+1 to n

let H_i be the min of (h_i + p)

assume i > j :

h_j <= H_i - sqrt(i-j)

h_j + sqrt(i-j) <= H_i ; find max of h_j + sqrt(i-j)


find intersect of

h[k] + sqrt(x-k) = h[j] + sqrt(x-j) // h[k] >= h[j]

h[k] - h[j] = sqrt(x-j) - sqrt(x-k)

A = sqrt(x-j) - sqrt(x-k)

sqrt(x-k) = sqrt(x-j) - A

x-k = x-j + A^2 - 2(sqrt(x-j))A
2(sqrt(x-j))A = k-j + A^2
sqrt(x-j) = (k-j)/2A + A/2 = B

x-j = B^2

x = B^2 + j -> solved

*/
