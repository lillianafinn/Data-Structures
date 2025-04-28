//building heap incrementally in O(N log N) time
#include <iostream>
using namespace std;

#include "heap.h"

int main(int argc , char *argv[]){
  heap<key_t> H;

  key_t key;
  while(cin >> key){
    H.push(key);
  }
  while(!H.empty()){
    cout << H.top() << endl;
    H.pop();

  }
}