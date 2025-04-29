//
// Created by Lilliana York on 4/29/2025.
//

#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>

using namespace std;

template <typename Tkey>
class bst {
    struct node {
      node() { key = Tkey(); left = NULL; right = NULL; }
      void print();

      Tkey key;
      node* left;
      node* right;
    };

    public:
      bst() {Troot = NULL;}
      ~bst() {clear(Troot); }

      bool empty() {return Troot == NULL;}
      void clear() {clear(Troot); Troot = NULL;}
      int num_nodes() {return num_nodes(Troot);}
      int num_leaves() {return num_leaves(Troot);}
      int height() {return height(Troot);}

      void insert(Tkey& key) {Troot = insert(Troot, key);}

      void print_inorder() {print_inorder(Troot);}
      void print_levelorder();

    private:
        void clear(node *);
        int num_nodes(node *);
        int num_leaves(node *);
        int height(node *);

        node* insert(node*, Tkey &);

        void print_inorder(node *);

        node *Troot;


};




#endif //BST_H

