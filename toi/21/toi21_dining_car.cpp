/*
    author  : PakinDioxide
    created : 24/05/2025 01:46
    task    : toi21_dining_car
*/
#include <bits/stdc++.h>
#include "dining_car.h"
#define ll long long

using namespace std;

pair <int, int> locate_dining_cars(int n) {
    int l = 1, r = n, ans1 = 0;
    while (l <= r) {
        if (l == r) { ans1 = l; break; }
        int x1 = l + (r-l)/2, x2 = x1+1;
        int p = compare_cars(x1, x2);
        if (p < 0) r = x1;
        else l = x2;
    }
    int k = min(ans1-1, n-ans1);
    int X = compare_cars(ans1-k, ans1+k);
    if ((X == 0 && n-ans1>ans1-1) || X == 1) {
        l = ans1+1, r = n; int ans2 = 0;
        while (l <= r) {
            if (l == r) { ans2 = l; break; }
            int x1 = l + (r-l)/2, x2 = x1+1;
            int p = compare_cars(x1, x2);
            if (p < 0) r = x1;
            else l = x2;
        }
        return make_pair(ans1, ans2);
    } else {
        l = 1, r = ans1-1; int ans2 = 0;
        while (l <= r) {
            if (l == r) { ans2 = l; break; }
            int x1 = l + (r-l)/2, x2 = x1+1;
            int p = compare_cars(x1, x2);
            if (p <= 0) r = x1;
            else l = x2;
        }
        return make_pair(ans2, ans1);
    }
}