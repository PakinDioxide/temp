#include "combo.h"
#include <bits/stdc++.h>

using namespace std;

string guess_sequence(int n) {
    char f = ' ';
    if (press("AB")) {
        if (press("A")) f = 'A';
        else f = 'B';
    } else {
        if (press("X")) f = 'X';
        else f = 'Y';
    }
    vector <string> str;
    string cmb = "", ccmb = "ABXY";
    for (char e : ccmb) if (e != f) cmb.push_back(e);
    cerr << "CMB : " << cmb << '\n';
    cerr << "FST : " << f << '\n';
    int rt = 0, rrt = 0, l = 1;
    for (int i = 0; i < 3; i++) {
        str.push_back("");
        str[i] += f;
    }
    while (l == 1) {
        string p = "";
        for (int i = 0; i < str.size(); i++) {
            while (str[i].size() > l) str[i].pop_back();
            while (str[i].size() < n) str[i] += cmb[(i+rt)%3];
            p += str[i];
        }
        cerr << "STR : ";
        for (auto e : str) cerr << e << ' ';
        cerr << '\n';
        rrt = rt;
        if (rt == 2) {rt = (rt+1)%3, l++; break;}
        int k = press(p);
        if (k > l) l = k;
        rt = (rt+1)%3;
    }
    while (l < n) {
        string p = "";
        for (int i = 0; i < str.size(); i++) {
            while (str[i].size() > l) str[i].pop_back();
            while (str[i].size() < n) str[i] += cmb[(i+rt)%3];
            p += str[i];
        }
        cerr << "STR : ";
        for (auto e : str) cerr << e << ' ';
        cerr << '\n';
        int k = press(p);
        cerr << "K : " << k << ' ' << l << '\n';
        cerr << "RT : " << rt << ' ' << rrt << '\n';
        if (k > l) l = k, rrt = rt, rt = (rt+1)%3;
        else {
            // rrt = (rt+1)%3;
            // rt = (rrt+1)%3;
            rt = (rt+1)%3;
            if (rt == rrt) rt = (rt+1)%3;
            rrt = rt;
            // for (int i = 0; i < str.size(); i++) {
            //     while (str[i].size() > l) str[i].pop_back();
            //     while (str[i].size() < l+1) str[i] += cmb[(i+rt)%3];
            // }
            // rt = (rt+1)%3;
            // l++;
            // cerr << "NEW STR : ";
            // for (auto e : str) cerr << e << ' ';
            // cerr << '\n';
        }
    }
    cerr << "STR : ";
    for (auto e : str) cerr << e << ' ';
    cerr << '\n';
    if (press(str[0]) == n) return str[0];
    else if (press(str[1]) == n) return str[1];
    return str[2];
}

/*
ABXXYXYXBB
ABXXBXB

[IMPORTANT] : THE FIRST LETTER APPERE ONLY ONCE

let Y be the first one
so we have X A B left

let the original string be "YBA"
we can ask 5 questions

we used 2 for finding the first one already -> 3 left

we have to get one character when we ask one time

binary searching uses 2 -> we have to change the way

we can add up to 4n long combos -> should have sth to do with it

YAA YBB YXX -> 2 -> so we know that we should cut at 2 
YA YB YX
YAB YBX YXA -> if no then it will be sth in YAX YBA YXB
*/