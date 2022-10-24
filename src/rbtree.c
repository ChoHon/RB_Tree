#include "rbtree.h"

#include <stdlib.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  node_t *nil = (node_t *)malloc(sizeof(node_t));
  nil->color = RBTREE_BLACK;
  nil->key = NULL;
  nil->left = NULL;
  nil->right = NULL;
  nil->parent = NULL;

  p->nil = nil;
  p->root = NULL;

  return p;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  free(t);
}

void rbtree_rotateRight(rbtree *t, node_t *parent_n) {
  node_t *left_child = parent_n->left;
  
  // 왼쪽 자식의 오른쪽 자식을 자신의 왼쪽에 붙인다
  parent_n->left = left_child->right;
  if (left_child->right != t->nil) left_child->right->parent = parent_n;

  // 왼쪽 자식을 자신의 부모와 붙인다
  left_child->parent = parent_n->parent;
  //자신의 부모가 없으면 root
  if (parent_n->parent == NULL) t->root = left_child;
  else {
    if (parent_n == parent_n->parent->left) parent_n->parent->left = left_child;
    else parent_n->parent->right = left_child;
  }

  // 왼쪽 자식의 오른쪽에 자신을 붙인다
  left_child->right = parent_n;
  parent_n->parent =left_child;
}

void rbtree_rotateLeft(rbtree *t, node_t *parent_n) {
  node_t *right_child = parent_n->right;
  
  // 오른쪽 자식의 왼쪽 자식을 자신의 오른쪽에 붙인다
  parent_n->right = right_child->left;
  if (right_child->left != t->nil) right_child->left->parent = parent_n;

  // 오른쪽 자식을 자신의 부모와 붙인다
  right_child->parent = parent_n->parent;
  //자신의 부모가 없으면 root
  if (parent_n->parent == NULL) t->root = right_child;
  else {
    if (parent_n == parent_n->parent->left) parent_n->parent->left = right_child;
    else parent_n->parent->right = right_child;
  }

  // 오른쪽 자식의 왼쪽에 자신을 붙인다
  right_child->left = parent_n;
  parent_n->parent =right_child;
}

void rbtree_insert_fix(rbtree *t, node_t *node) {
  while (node != t->root && node->parent->color == RBTREE_RED) {
    if (node->parent == node->parent->parent->left) {
      node_t *uncle = node->parent->parent->right;

      if (uncle->color == RBTREE_RED) {
        node->parent->color = RBTREE_BLACK;
        uncle->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;

        node = node->parent->parent;
      } else {
        if (node == node->parent->right) {
          node = node->parent;
          rbtree_rotateLeft(t, node);
        }
        node->parent->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;
        rbtree_rotateRight(t, node->parent->parent);        
      }
    }
    else {
      node_t *uncle = node->parent->parent->left;

      if (uncle->color == RBTREE_RED) {
        node->parent->color = RBTREE_BLACK;
        uncle->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;

        node = node->parent->parent;
      } else {
        if (node == node->parent->left) {
          node = node->parent;
          rbtree_rotateRight(t, node);
        }
        node->parent->color = RBTREE_BLACK;
        node->parent->parent->color = RBTREE_RED;
        rbtree_rotateLeft(t, node->parent->parent);        
      }      
    }
  }
  
  t->root->color = RBTREE_BLACK;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  node_t *cur_node = t->root;
  node_t *prev_node = NULL;

  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->color = RBTREE_RED;
  new_node->key = key;
  new_node->parent = NULL;
  new_node->left = t->nil;
  new_node->right = t->nil;

  if (t->root == NULL) t->root = new_node;

  while (cur_node != t->nil) {
    prev_node = cur_node;
    if (cur_node->key < new_node->key) cur_node = cur_node->right;
    else cur_node = cur_node->left;
  }

  new_node->parent = prev_node;
  if (prev_node->key > new_node->key) prev_node->left = new_node;
  else prev_node->right = new_node;

  rbtree_insert_fix(t, new_node);

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  node_t *cur_node = t->root;
  node_t *prev_node = NULL;

  while (cur_node->key != key && cur_node != t->nil) {
    if (cur_node->key > key) cur_node = cur_node->left;
    else cur_node = cur_node->right;
  }

  if (cur_node->key == key) return cur_node;
  else return NULL;
}

node_t *rbtree_min(const rbtree *t) {
  node_t *cur_node = t->root;

  for (; cur_node->left != t->nil; cur_node = cur_node->left)

  return cur_node;
}

node_t *rbtree_max(const rbtree *t) {
  node_t *cur_node = t->root;

  for (; cur_node->right != t->nil; cur_node = cur_node->right)

  return cur_node;
}

int rbtree_erase(rbtree *t, node_t *p) {
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  return 0;
}
