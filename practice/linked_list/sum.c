#include "linked_list.c"

int sum_of_liked_list(ListNode *list) {
	int sum = 0;
	ListNode *p = list;

	for (; p != NULL; p = p->link) sum += p->data;

	return sum;
}

int main(void) {
	ListNode *pa1, *pa2, *pa3;
	pa1 = (ListNode *)malloc(sizeof(ListNode));
	pa1->data = 10;
	pa1->link = NULL;

	pa2 = (ListNode *)malloc(sizeof(ListNode));
	pa2->data = 20;
	pa2->link = NULL;
	pa1->link = pa2;

	pa3 = (ListNode *)malloc(sizeof(ListNode));
	pa3->data = 30;
	pa3->link = NULL;
	pa2->link = pa3;

	ListNode *pb1, *pb2, *pb3;
	pb1 = (ListNode *)malloc(sizeof(ListNode));
	pb1->data = 40;
	pb1->link = NULL;

	pb2 = (ListNode *)malloc(sizeof(ListNode));
	pb2->data = 50;
	pb1->link = pb2;

	pb3 = (ListNode *)malloc(sizeof(ListNode));
	pb3->data = 60;
	pb3->link = NULL;
	pb2->link = pb3;

	printf("%d\n", sum_of_liked_list(pa1));

	return 0;
}