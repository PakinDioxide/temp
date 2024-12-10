#include <bits/stdc++.h>

using namespace std;

int main() {
    char s[8], a[6], b[7], c[7];
    scanf("%s", &s);
    int x = 10*(s[0]-'0') + (s[1]-'0'), y = 10*(s[3]-'0') + (s[4]-'0'), z = 10*(s[6]-'0') + (s[7]-'0');
    for (int i = 5; i >= 0; i--) {
        if (i != 5) a[i] = (!(x%2))+'0', x /= 2;
        b[i] = (!(y%2))+'0', c[i] = (!(z%2))+'0';
        y /= 2, z /= 2;
    }
    a[5] = b[6] = c[6] = 0;
    printf("%s:%s:%s", a, b, c);
}