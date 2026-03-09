#include "combo.h"
#include <bits/stdc++.h>

using namespace std;

string guess_sequence(int n) {
    vector <string> v;
    string s = "";
    if (press("XY")) {
        if (press("X")) s = "X";
        else s = "Y";
    } else {
        if (press("A")) s = "A";
        else s = "B";
    }
    if (s != "A") v.emplace_back("A");
    if (s != "B") v.emplace_back("B");
    if (s != "X") v.emplace_back("X");
    if (s != "Y") v.emplace_back("Y");
    for (int i = 1; i < n-1; i++) {
        string ask = s;
        ask += v[0];
        for (int i = 0; i < 3; i++) ask += (s + v[1] + v[i]);
        int k = press(ask) - s.size();
        if (k == 0) s += v[2];
        else if (k == 1) s += v[0];
        else s += v[1];
    }
    if (n > 1) {
        if (press(s + v[0]) == n) s += v[0];
        else if (press(s + v[1]) == n) s += v[1];
        else s += v[2];
    }
    return s;
}
