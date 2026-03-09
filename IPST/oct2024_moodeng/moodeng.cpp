#include "moodeng.h"
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void search(int N, int M, int T) {
    if (N == 1) {
        vector <vector <bool>> Q1(N, vector <bool>(M));
        for (int i = 0; i < M; i += 2) Q1[0][i] = 1;
        int idx = 0;
        if (query(Q1)) idx = 1;
        int L = 0, R = M-1;
        for (int i = 0; i < T; i++) {
            if (L % 2 != idx) L++;
            if (R % 2 != idx) R--;
            int x = L + (R-L)/2;
            vector <vector <bool>> Q(N, vector <bool>(M));
            for (int i = L; i <= x; i++) if (i % 2 == idx) Q[0][i] = 1;
            if (query(Q)) L = max(0, --L), R = min(x+1, M-1);
            else R = min(++R, M-1), L = x;
            idx ^= 1;
        }
    } else {
        vector <vector <bool>> Q1(N, vector <bool>(M));
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if ((i+j) % 2 == 0) Q1[i][j] = 1;
        int idx = query(Q1);
        int L1 = 0, R1 = N+M-2, L2 = -(M-1), R2 = (N-1);
        for (int ii = 0; ii < T; ii++) {
            if (L1 % 2 != idx) L1++;
            if (R1 % 2 != idx) R1--;
            if (abs(L2 % 2) != idx) L2++;
            if (abs(R2 % 2) != idx) R2--;
            int x1 = L1 + (R1 - L1)/2, x2 = L2 + (R2 - L2)/2;
            vector <vector <bool>> Q(N, vector <bool>(M));
            // cout << L1 << ' ' << R1 << ' ' << L2 << ' ' << R2 << '\n';
            if (ii % 2 == 0) {
                for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
                    if ((i+j) % 2 == idx && L1 <= i+j && i+j <= x1 && L2 <= i-j && i-j <= R2) Q[i][j] = 1;
                }
                if (query(Q)) L1 = max(0, --L1), R1 = min(x1+1, (N+M-2));
                else R1 = min(++R1, (N+M-2)), L1 = x1;
                L2 = max(-(M-1), --L2);
                R2 = min(++R2, (N-1));
            } else {
                for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
                    if ((i+j) % 2 == idx && L1 <= i+j && i+j <= R1 && L2 <= i-j && i-j <= x2) Q[i][j] = 1;
                }
                if (query(Q)) L2 = max(-(M-1), --L2), R2 = min(x2+1, (N-1));
                else R2 = min(++R2, (N-1)), L2 = x2;
                L1 = max(0, --L1);
                R1 = min(++R1, (N+M-2));
            }
            idx ^= 1;
        }
    }
}
