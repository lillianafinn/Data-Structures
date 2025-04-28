//same as heap2.cpp only using STL algorithms
#include <iostream>
#include <algorithm>
using namespace std;

#include "heap.h"

int main(int argc , char *argv[]){
    vector<key_t> A;

    key_t key;
    while(cin >> key){
        A.push_back(key);
    }

    make_heap(A.begin(),A.end());

    while(!H.empty()){
        cout << A.front() << "\n ";
        pop_heap(A.begin(),A.end());
        A.pop_back();

    }
}
//
//NOTE: STL heaps are max-heaps. The output of the STL programs
//are thus "reversed" relative to the homegrown min-heap.
