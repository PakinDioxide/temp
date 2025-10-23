#include <bits/stdc++.h>

using namespace std;

int y[100002], n, q;
int lsb(int num) { return num & -num; }

int prefixSum(int i) {
  i += 1;
  int sum = 0;
  while (i != 0) {
    sum += y[i];
    i -= lsb(i);
  }
  return sum;
}

void adjust(int i, int v) {
  i += 1;
  while (i < 11) {
    y[i] += v;
    i += lsb(i);
  }
}

int sum(int i, int j) {
  if (j < i) {
    i ^= j;
    j ^= i;
    i ^= j;
  }
  return prefixSum(j) - prefixSum(i - 1);
}

void update(int i, int v) {
  int diff = v - sum(i, i);
  adjust(i, diff);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {adjust(i, s[i]-'0');}

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) update(b-1, c);
        else {
            int ans = 0;
            for (int j = b-1; j < c; j++) {
                for (int k = j; k < c; k++) {
                    if (sum(j, k) % 3 == 0) ans++;
                }
            }
            cout << ans << '\n';
        }
    }
}
