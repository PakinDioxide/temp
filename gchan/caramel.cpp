#include <bits/stdc++.h>

using namespace std;

bool isInCaramel(char c) {
    for (char i : "CaRaMeL") if (i == c) return 1;
    return 0;
}