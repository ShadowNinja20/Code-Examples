#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "priority_queue.h"

Node* pq_enqueue(Node** a_head, void* a_value, int (*cmp_fn)(const void*, const void*)) {
	Node* new_node = malloc(sizeof(*new_node));
	*new_node = (Node) { .a_value = a_value, .next = NULL };
	Node* tail = *a_head;
	if(*a_head == NULL || cmp_fn((*a_head) -> a_value, new_node -> a_value) > 0) { 
		new_node -> next = *a_head;
		(*a_head) = new_node;
	}
	else { 
		while(tail -> next != NULL && \
			  cmp_fn(tail -> next -> a_value, new_node -> a_value) <= 0) {
			tail = tail -> next;
		}
		new_node -> next = tail -> next;
		tail -> next = new_node;
	}
	return(new_node);  
}
Node* pq_dequeue(Node** a_head) {
	Node* removed_node = *a_head;
	if(*a_head != NULL) {
		*a_head = (*a_head) -> next; 
		removed_node -> next = NULL; 
	}
	return removed_node; 
}
Node* stack_push(Node** a_head, void* a_value) {
	return &(Node) { .a_value = a_value , .next = *a_head }; 
}
Node* stack_pop(Node** a_head) {
	Node* temp = *a_head; 
	*a_head = (*a_head) -> next; 
	return temp; 
}
void destroy_list(Node** a_head, void (*destroy_value_fn)(void*)) {
	while((*a_head) != NULL) {
		Node* head = stack_pop(a_head);
		destroy_value_fn((head) -> a_value);
		free(head);
	}
	*a_head = NULL;
}
#define HUFFMAN_C_V1
