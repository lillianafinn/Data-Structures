//BST (key) tree example
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

typedef int key_type;

template <typename Iterator>
void print(Iterator p0, Iterator p1){
  while(p0 != p1){
    cout << *(p0++) << " ";
    ++p0;
  }
  cout << endl;
}

int main(int argc, char *argv[]){
  set<key_type> A;

  key_type key;
  while(cin >> key){
    A.insert(key);

  }
  print(A.begin(), A.end());
}

//hint: A set is balanced BST for uniue key instances
//hint: a multiset allows key duplicates