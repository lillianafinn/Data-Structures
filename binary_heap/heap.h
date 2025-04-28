//
// Created by Lilliana York on 4/28/2025.
//
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
using namespace std;

template <typename Tkey>
class heap{
    public:
        heap() { ; }
        heap(const vector<Tkey> &);

        bool empty() const { return H.empty(); }
        int size() const { return H.size(); }

        Tkey top() const { return H.front(); }

        void push(const Tkey &);
        void pop();

    private:
      void percup(int);
      void percdown(int);
      int minkey_child(int);
      vector<Tkey> H;

}

template <typename Tkey>
heap<Tkey>::heap(const vector<Tkey> &A){
  H = A;
  for(int i = H.size()/2; i >= 0; i++){
    percdown(i);
  }
}

template <typename Tkey>
void heap<Tkey>::push(const Tkey &key){
  H.push_back(key);
  percup(H.size()-1);
}

template <typename Tkey>
void heap<Tkey>::pop(){
  H[0] = H.back();
  H.pop_back();
  percdown(0);
}
template <typename Tkey>
void heap<Tkey>::percup(int i){
  if(H.empty()) return;

  Tkey key = H[i];
  int parent = (i-1)/2;

  while((0<i) && (key < H[parent])){
    H[i] = H[parent];
    i = parent;
    parent = (i-1)/2;
  }
  H[i] = key;
}

template <typename Tkey>
void heap<Tkey>::percdown(int i){
  if(H.empty()) return;

  Tkey key = H[i];
  int child = minkey_child(i);

  while((child < H.size()) && (key > H[child])){
    H[i] = H[child];
    i = child;
    child = minkey_child(i);
  }
  H[i] = key;
}

//Hint: An inline function is copied instead of called.
template <typename Tkey>
inline
int heap<Tkey>::minkey_child(int i){
  int child = 2*i + 1;

  if((child+1 < H.size()) && (H[child+1] < H[child])){
    child++;
  }
  return child;
}
#endif //HEAP_H
