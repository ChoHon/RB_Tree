#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;

void display(ListNode *list) {
	ListNode *node = list;
	printf("( ");
	for (; node != NULL; node = node->link) printf("%d ", node->data);
	printf(" )");
}

ListNode* make_node(element data) {
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = data;
	p->link = NULL;

	return p;
}

ListNode* link_node(ListNode *node, ListNode *pre_node) {
	pre_node->link = node;
	pre_node = node;

	return pre_node;
}
