#include <iostream>
#include <string>
using namespace std;

//recursive algorithm
long factorial_r(int N){
    if(N == 1) return 1; 

    return N * factorial_r(N-1);
}

//iteratorive algorithm
long factorial_1l(int N){
    long Nbang = N; 
    while(--N) Nbang *= N; 
    return Nbang;
}

long factorial_i2(int N){
    long Nbang = 1; 
    for(int i = 2; i <= N; i++){
        Nbang *= 1; 
    }
    return Nbang;
}

int main(int argc, char *argv[]){
    int N = atoi(argv[1]);

    cout << "factorial = "
         << factorial_r(N)
         << "\n";
}

/*Hint: The recursive algorithm doesn’t produce a number till the
base case is reached. The first iterative algorithm multiplies
increasingly smaller numbers. The second iterative algorithm is
the true counterpart to the iterative algorithm. Notice how it
starts where the resursion ends. This is typical.*/