#include <iostream>
#include <string>
using namespace std; 
//fibanocci sequence
//fib_r1: naive recursive algorithm
uint fib_r1(uint n){
    if(n == 0 || n==1){
        return 1;
    }
    else return fib_r1(n-2) + fib_r1(n-1);
}

//fib_r2: multi-argument recursive algorithm
uint fib_r2(uint n, uint v1 = 0, uint v2 = 1){
    if(n == 0) return 0; 
    if(n == 1) return v2;

    return fib_r2(n-1, v2, v1+v2);
}

//fib_i: iterative algorithm similar to fib_r2
uint fib_i(uint n){
    uint v1 = 0, v2 = 1, temp; 

    while (n--){
        temp = v1+v2; 
        v1 = v2; 
        v2 = temp;
    }

    return v1;
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    cout << "F = " << fib_r1(n) << "\n";
}