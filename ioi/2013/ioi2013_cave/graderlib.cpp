#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include "cave.h"

#define MAX_N 5000
#define MAX_CALLS 70000

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

/* Symbol obfuscation */
#define N koala
#define realS kangaroo
#define realD possum
#define inv platypus
#define num_calls echidna

static int N;
static int realS[MAX_N];
static int realD[MAX_N];
static int inv[MAX_N];
static int num_calls;

void answer(int S[], int D[]) {
    int i;
    int correct = 1;
    for (i = 0; i < N; ++i)
        if (S[i] != realS[i] || D[i] != realD[i]) {
            correct = 0;
            break;
        }

    if (correct)
        printf("CORRECT\n");
    else
        printf("INCORRECT\n");

    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", S[i]);
    }
    printf("\n");

    for (i = 0; i < N; ++i) {
        if (i > 0)
            printf(" ");
        printf("%d", D[i]);
    }
    printf("\n");

    exit(0);
}

int tryCombination(int S[]) {
    int i;

    if (num_calls >= MAX_CALLS) {
        printf("INCORRECT\nToo many calls to tryCombination().\n");
        exit(0);
    }
    ++num_calls;

    for (i = 0; i < N; ++i)
        if (S[inv[i]] != realS[inv[i]])
            return i;
    return -1;
}

int init() {
    int i, res;

    FILE *f = fopen("cave.in", "r");
	if (!f)
		fail("Failed to open input file.");

	res = fscanf(f, "%d", &N);

    for (i = 0; i < N; ++i) {
        res = fscanf(f, "%d", &realS[i]);
    }
    for (i = 0; i < N; ++i) {
        res = fscanf(f, "%d", &realD[i]);
        inv[realD[i]] = i;
    }

    num_calls = 0;
    return N;
}

// void exploreCave(int n) {
//     // // SUBTASK 1
//     // int idx = 0, a[n] = {}, b[n];
//     // for (int i = 0; i < n; i++) b[i] = i;
//     // while ((idx = tryCombination(a)) != -1) {
//     //     a[idx] = 1;
//     // }
//     // answer(a, b);
    
//     // SUBTASK 2
//     // int a[n] = {}, b[n] = {};
//     // for (int i = 0; i < n; i++) {
//     //     a[i] = 1;
//     //     b[i] = tryCombination(a);
//     //     a[i] = 0;
//     // }
//     // answer(a, b);

//     // FULL
//     int idx = 0, a[n] = {}, b[n] = {}, v[n] = {};
//     idx = tryCombination(a);
//     while (idx != -1) {
//         for (int i = 0; i < n; i++) {
//             if (v[i]) continue;
//             a[i] = 1;
//             int id = tryCombination(a);
//             if (id == -1 || id > idx) {
//                 v[i] = 1;
//                 b[i] = idx+1;
//                 idx = id;
//                 break;
//             } else if (id < idx) {
//                 v[i] = 1;
//                 a[i] = 0;
//             } else a[i] = 0;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (b[i]) b[i]--;
//         else {
//             a[i] = abs(a[i]-1);
//             b[i] = tryCombination(a);
//             a[i] = abs(a[i]-1);
//         }
//     }
//     answer(a, b);
// }