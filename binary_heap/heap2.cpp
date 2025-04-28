//building heap using heapify in O(N) time
#include <iostream>
using namespace std;

#include "heap.h"

int main(int argc , char *argv[]){
    vector<key_t> A;

    key_t key;
    while(cin >> key){
        A.push_back(key);
    }
     heap<string> H(A);

    while(!H.empty()){
        cout << H.top() << endl;
        H.pop();

    }
}