#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "huffman.h"
#include "miniunit.h"

static void _destroy_fn(void* a_value){
	free((a_value));
}

int _test_1() {
	mu_start();

	Frequencies freqs = {0}; 
	const char* error;
	calc_frequencies(freqs, "test.txt", &error);
	Node* head = NULL;
	head = make_huffman_pq(freqs);
//	for(Node* curr = head; curr != NULL; curr = curr -> next) {
//		printf("%c\n",((TreeNode*)(curr -> a_value)) -> character);
//	}
	mu_check(((TreeNode*)(head -> a_value)) -> character == '\n');
	mu_check(((TreeNode*)(head -> a_value)) -> frequency == 1);
	mu_check(((TreeNode*)(head -> next -> a_value)) -> frequency == 1);
	mu_check(((TreeNode*)(head -> next -> a_value)) -> character == 'b');
	destroy_list(&head, _destroy_fn);

	mu_end();
}

int main(int argc, char* argv[]) {
	mu_run(_test_1);
/*
	Frequencies freqs = {0};
	const char* error;
	calc_frequencies(freqs, "test.txt", &error);
	Node* head = NULL;
	head = make_huffman_pq(freqs);
	for(Node* curr = head; curr != NULL; curr = curr -> next) {
		printf("%c\n",((TreeNode*)(curr -> a_value)) -> character);
	}
	destroy_list(&head, _destroy_fn);
*/
	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
