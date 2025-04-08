#include <iostream>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; 
    cin >> N;
    
    // For N = 2 or 3, no pandiagonal Latin square exists.
    if (N % 12 == 5) {
        int grid[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = (i + 2 * j) % N + 1;
            }
        }
    
        // Print the generated Latin square
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << (j == N - 1 ? "\n" : " ");
            }
        }
        return 0;
    }

    if (N % 12 == 7) {
        int grid[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = (i + 3 * j) % N + 1;
            }
        }

        // Print the generated Latin square
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j] << (j == N - 1 ? "\n" : " ");
            }
        }

        return 0;
    }

    if(N == 2 || N == 3 || !(N % 12 == 1 || N % 12 == 11)){
        cout << -1 << "\n";
        return 0;
    }
    
    
    // We work with 0-indexed rows and columns and output numbers 1..N.
    if(N % 2 == 1){
        // For odd N, choose constant c = 2.
        // Then a[i][j] = ( i + 2*j ) mod N + 1 gives a Latin square
        // that also has every wrapped diagonal (both main and anti-diagonals)
        // containing a permutation of 1..N.
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int val = ( i + 2 * j ) % N;
                cout << val + 1 << (j == N - 1 ? "\n" : " ");
            }
        }
    }
    else {
        // For even N, use the following construction:
        // a[i][j] = ( i + j + (N/2) * ((i+j) mod 2) ) mod N + 1.
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                int add = ((i + j) % 2);
                int val = ( i + j + (N/2) * add ) % N;
                cout << val + 1 << (j == N - 1 ? "\n" : " ");
            }
        }
    }
    return 0;
}
