#include "cave.h"
#include <bits/stdc++.h>

using namespace std;

void exploreCave(int n) {
    // // SUBTASK 1
    // int idx = 0, a[n] = {}, b[n];
    // for (int i = 0; i < n; i++) b[i] = i;
    // while ((idx = tryCombination(a)) != -1) {
    //     a[idx] = 1;
    // }
    // answer(a, b);
    
    // SUBTASK 2
    // int a[n] = {}, b[n] = {};
    // for (int i = 0; i < n; i++) {
    //     a[i] = 1;
    //     b[i] = tryCombination(a);
    //     a[i] = 0;
    // }
    // answer(a, b);

    // // FULL V1 : TOO MANY CALLS
    // int idx = 0, a[n] = {}, b[n] = {}, v[n] = {};
    // idx = tryCombination(a);
    // while (idx != -1) {
    //     for (int i = 0; i < n; i++) {
    //         if (v[i]) continue;
    //         a[i] = 1;
    //         int id = tryCombination(a);
    //         if (id == -1 || id > idx) {
    //             v[i] = 1;
    //             b[i] = idx+1;
    //             idx = id;
    //             break;
    //         } else if (id < idx) {
    //             v[i] = 1;
    //             a[i] = 0;
    //         } else a[i] = 0;
    //     }
    // }
    // for (int i = 0; i < n; i++) {
    //     if (b[i]) b[i]--;
    //     else {
    //         a[i] = abs(a[i]-1);
    //         b[i] = tryCombination(a);
    //         a[i] = abs(a[i]-1);
    //     }
    // }
    // answer(a, b);

    // // FULL V2
    int a[n] = {}, b[n] = {};
       
}