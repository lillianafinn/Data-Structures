//
// Created by Lilliana York on 4/29/2025.
//
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#include "bst.h"

template <typename Tkey>
void bst<Tkey>::node::print(){
    cout << key << " :";
    if(left) cout << " L=" << left->key;
    if(right) cout << " R=" << right->key;
    cout << endl;
}

template <typename Tkey>
void bst<Tkey>::clear(node *T){
    if(T){
        clear(T->left);
        clear(T->right);
        delete T;
        T = NULL;
    }
}

template <typename Tkey>
int bst<Tkey>::num_nodes(node *T){
    if(T == NULL) return 0;

    return 1 + num_nodes(T->left) + num_nodes(T->right);
}

template <typename Tkey>
int bst<Tkey>::num_leaves(node *T){
    if(T == NULL) return 0;

    if(T->left == NULL && T->right == NULL) return 1;
    return num_leaves(T->left) + num_leaves(T->right);
}

template <typename Tkey>
int bst<Tkey>::height(node *T){
    if(T == NULL) return -1;

    int left = height(T->left);
    int right = height(T->right);

    return 1 + max(left, right);
}

template <typename Tkey>
struct bst<Tkey>::node *bst<Tkey>::insert(node *T, Tkey &key){
    if(T == NULL){
        T = new node(key);
        T->key = key;
    }
    else if(key == T->key){}
    else if(key < T->key) T->left = insert(T->left, key);
    else T->right = insert(T->right, key);

    return T;
}

template <typename Tkey>
void bst<Tkey>::print_inorder(node *T){
    if(T){
        print_inorder(T->left);
        T->print();
        print_inorder(T->right);
    }
}

template <typename Tkey>
void bst<Tkey>::print_levelorder(){
    if(Troot == NULL) return;

    queue<node *> q;
    node *t;

    q.push(Troot);
    while(!q.empty()){
        t = q.front();
        q.pop();

        t->print();
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);

    }
}