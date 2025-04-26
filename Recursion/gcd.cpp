#include <iostream>
#include <string>
using namespace std;

//gcd_r: iterative algorithm
int gcd_r1(int x, int y){
    if(y == 0) return x; 

    if(y<x) return gcd_r1(x-y, y);
    else return gcd_r1(x, y-x);
}

int gcd_r2(int x, int y){
    if(y == 0) return x; 

    return gcd_r2(y, x%y);
}

//iterative algorithm
int gcd_i1(int x, int y){
    while(y != 0){
        if(y < x) x -= y; 
        else y -= x; 
    }
    return x; 
}

int gcd_12(int x, int y){
    int temp; 
    while(y != 0){
        temp = y; 
        y = x % y; 
        x = temp;
    }
    return x;
}

int main(int argc, char *argv[]){
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    cout << "gcd = " << gcd_r2(x, y) << endl;
}