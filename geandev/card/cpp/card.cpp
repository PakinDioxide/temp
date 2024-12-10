#include <bits/stdc++.h>
#include "card.h"

using namespace std;

namespace SHIN{
    int variable_example = 0;
}

namespace LENA{
    int variable_example = 0;
}

std::vector<int> Shin(int n, std::vector<int> a) {
    sort(a.begin(), a.end());

    return {1, 2, 3, 4, 5};
    // SHIN::variable_example++;
    // return {60, 80, 6, 0, 8};
}

int Lena(int n, std::vector<int> b) {
    return 0;
    // LENA::variable_example++;
    // return 68;
}

/*
8
1 3 5 6 7 8
 2 2 1 1 1
  4 3 2 2

*/

int main() {
    vector <int> a = {1, 2, 3, 4, 6};
    for (int i = 1; i < 7; i++) next_permutation(a.begin(), a.end());
    int cnt = 0;
    while (next_permutation(a.begin(), a.end())) cnt++;  
    for (int i : a) cout << i << ' ';
    cout << '\n' << 120-cnt;  
}