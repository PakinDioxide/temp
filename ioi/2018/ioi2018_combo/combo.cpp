#include "combo.h"
#include <bits/stdc++.h>

using namespace std;

string guess_sequence(int n) {
    char a[4] = {'A', 'B', 'X', 'Y'};
    string s = "";
    while (s.size() < n) {
        for (int i = 0; i < 4; i++) {
            string ns = a[i] + s + s + a[i];
            if (press(ns) > s.size()) {
                if (press(a[i] + s) > s.size()) s = a[i] + s;
                else s = s + a[i];
            }
        }
    }
    return s;
}