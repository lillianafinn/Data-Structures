//BST (key, value) example

#include <utility>
#include <iostream>
#include <map>
using namespace std;

typedef int key_type;
typedef int value_type;

int main(int argc, char *argv[]){
    map<key_type, value_type> A;

    key_type key;
    pair<map<key_type, value_type>::iterator, bool> status;


    while(cin >> key){
        A.insert(pair<key_type, value_type>(key, 1));
        if(status.second == false){
          status.first->second++;
        }
    }

    //print
    map<key_type, value_type>::iterator p;
    for(p = A.begin(); p != A.end(); p++){
        cout << " " << p->second << " " << p->first << "\n";
    }
}

//Hint: A map is balanced BST for (key,value) pairs.
//Hint: A multimap allows key duplicates.
//Hint: A pair is a template based struct that contains two elements called first and second.

