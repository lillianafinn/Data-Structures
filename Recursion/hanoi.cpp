#include <iostream>
#include <string>
using namespace std; 

void hanoi_r(int N, char S, char D, char T){
    if(N == 0) return;

    hanoi_r(N-1, S, T, D);
    cout << S << " to " << D << "\n";
    hanoi_r(N-1, T, D, S);
}
void hanoi_i(int N) {
    for (int m=1; m<(1<<N); m++) {
        char S = 'A' + ( (m & (m-1)) % 3);
        char D = 'A' + (((m | (m-1)) + 1) % 3);
        cout << S << " to " << D << "\n";
    }
}

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    enum { RECURSIVE, ITERATIVE } mode = RECURSIVE;
    
    switch (mode) {
    case RECURSIVE:
        if (N%2) hanoi_r(N, 'A', 'C', 'B');
        else hanoi_r(N, 'A', 'B', 'C');
        break;
    case ITERATIVE:
        hanoi_i(N);
        break;
    }
    }