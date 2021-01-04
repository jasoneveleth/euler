#include <stdio.h>
#include <stdlib.h>

typedef struct {
    struct node_t *lChild;
    struct node_t *rChild;
    void *data;
} node_t;

node_t *bintree_init(void *data) {
    node_t *root = (node_t *)malloc(sizeof(node_t));
    root->lChild = NULL;
    root->rChild = NULL;
    root->data = data;
    return root;
}

node_t *search(node_t *parent, node_t *target) {
    printf("%p, %p\n", (void *)parent, (void *)target);
    return NULL;
}

int main(void);
