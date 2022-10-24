#ifndef _RBTREE_H_
#define _RBTREE_H_

#include <stddef.h>

typedef enum { RBTREE_RED, RBTREE_BLACK } color_t;

typedef int key_t;

typedef struct node_t {
  color_t color;
  key_t key;
  struct node_t *parent, *left, *right;
} node_t;

typedef struct {
  node_t *root;
  node_t *nil;  // for sentinel
} rbtree;

rbtree *new_rbtree(void);
void delete_rbtree(rbtree *);

void rbtree_display(rbtree *t, node_t *node);

void rbtree_rotateRight(rbtree *t, node_t *parent_n);
void rbtree_rotateLeft(rbtree *t, node_t *parent_n);

void rbtree_insert_fix(rbtree *t, node_t *node);
node_t *rbtree_insert(rbtree *, const key_t);

node_t *rbtree_find(const rbtree *, const key_t);
node_t *rbtree_min(const rbtree *);
node_t *rbtree_max(const rbtree *);

void rbtree_erase_fix(rbtree *t, node_t *node);
int rbtree_erase(rbtree *, node_t *);

int rbtree_to_array(const rbtree *, key_t *, const size_t);

#endif  // _RBTREE_H_
