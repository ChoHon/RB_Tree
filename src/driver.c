#include "rbtree.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    rbtree *t = new_rbtree();

    rbtree_insert(t, 8);
    rbtree_insert(t, 7);
    rbtree_insert(t, 9);
    rbtree_insert(t, 3);
    rbtree_insert(t, 6);
    rbtree_insert(t, 4);
    rbtree_insert(t, 5);
    rbtree_insert(t, 12);

    rbtree_display(t, t->root);

    node_t *n;
    n = rbtree_find(t, 8);
    printf("%d\n", n->key);

    rbtree *sub_t = new_rbtree();
    sub_t->root = n->right;
    sub_t->nil = t->nil;

    printf("%d\n", rbtree_min(sub_t)->key);
    printf("%d\n", rbtree_max(sub_t)->key);

    rbtree_erase(t, t->root->left);

    rbtree_display(t, t->root);

    return 0;
}