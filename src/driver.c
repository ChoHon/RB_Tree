#include <assert.h>
#include "rbtree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void test_find_erase(rbtree *t, const key_t *arr, const size_t n) {
  for (int i = 0; i < n; i++) {
    node_t *p = rbtree_insert(t, arr[i]);
    assert(p != NULL);
  }

  for (int i = 0; i < n; i++) {
    node_t *p = rbtree_find(t, arr[i]);
    assert(p != NULL);
    assert(p->key == arr[i]);
    rbtree_erase(t, p);
  }

  for (int i = 0; i < n; i++) {
    node_t *p = rbtree_find(t, arr[i]);
    assert(p == NULL);
  }

  for (int i = 0; i < n; i++) {
    node_t *p = rbtree_insert(t, arr[i]);
    assert(p != NULL);
    node_t *q = rbtree_find(t, arr[i]);
    assert(q != NULL);
    assert(q->key == arr[i]);
    assert(p == q);
    rbtree_erase(t, p);
    q = rbtree_find(t, arr[i]);
    assert(q == NULL);
  }
}

void test_find_erase_rand(const size_t n, const unsigned int seed) {
  srand(seed);
  rbtree *t = new_rbtree();
  key_t *arr = calloc(n, sizeof(key_t));
  for (int i = 0; i < n; i++) {
    arr[i] = rand();
  }

  test_find_erase(t, arr, n);

  free(arr);
  delete_rbtree(t);
}

int main(int argc, char *argv[]) {

    test_find_erase_rand(1000000, 55);

    return 0;
}