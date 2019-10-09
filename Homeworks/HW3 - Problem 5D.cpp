#include <iostream>

static bool is_left_child(bst_node *p){
  //this will return true if parent is not empty and check to see if it's a left child
  return ((p->parent != nullptr) && (p->parent->left = p));
}

static bool is_right_child(bst_node *p){
  return ((p->parent != nullptr) && !is_left_child(p));
}

static bst_node * successor(bst_node *p) {
  if(p->right != nullptr){
    bst_node *c = p->right;
    while(c->left != nullptr){
      c = c->left; //traverse left till c->left is not nullptr
    }
    return c; //Once c->left is nullptr, c will be the successor
  }
  //if there is no right child then nearest acestor will be left child of parent
  while(p->parent != nullptr && !is_left_child(p)){
    p = p->parent;
  }
  return p->parent;
}
