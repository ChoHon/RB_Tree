#include "rbtree.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
    rbtree *t = new_rbtree();

    // 10, 5, 8, 34, 67, 23, 156, 24, 2, 12, 24, 36, 990, 25

    rbtree_insert(t, 10);
    rbtree_insert(t, 5);
    rbtree_insert(t, 8);
    rbtree_insert(t, 34);
    rbtree_insert(t, 67);
    rbtree_insert(t, 23);
    rbtree_insert(t, 156);
    rbtree_insert(t, 24);
    rbtree_insert(t, 2);
    rbtree_insert(t, 12);
    rbtree_insert(t, 24);
    rbtree_insert(t, 36);
    rbtree_insert(t, 990);
    rbtree_insert(t, 25);

    node_t *n = rbtree_find(t, 10);
    rbtree_erase(t, n);

    n = rbtree_find(t, 5);
    rbtree_erase(t, n);

    n = rbtree_find(t, 8);
    rbtree_erase(t, n);

    n = rbtree_find(t, 34);
    rbtree_erase(t, n);

    n = rbtree_find(t, 67);
    rbtree_erase(t, n);

    n = rbtree_find(t, 23);
    rbtree_erase(t, n);

    n = rbtree_find(t, 156);
    rbtree_erase(t, n);

    n = rbtree_find(t, 24);
    rbtree_erase(t, n);

    n = rbtree_find(t, 2);
    rbtree_erase(t, n);

    n = rbtree_find(t, 12);
    rbtree_erase(t, n);

    rbtree_display(t, t->root);

    // node_t *n;
    // n = rbtree_find(t, 6);
    // if (n != NULL) {
    //     printf("%d\n", n->key);

    //     rbtree *sub_t = new_rbtree();
    //     sub_t->root = n->right;
    //     sub_t->nil = t->nil;

    //     printf("%d\n", rbtree_min(sub_t)->key);
    //     printf("%d\n", rbtree_max(sub_t)->key);

    //     rbtree_erase(t, n);
    // }

    // rbtree_display(t, t->root);

    return 0;
}