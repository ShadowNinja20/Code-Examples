#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "sorts.h"

void _insert(BSTNode** a_root, int const* value) {
	if(*a_root == NULL) {
		BSTNode* new_root = malloc(sizeof(*new_root));
		*new_root = (BSTNode) { .value = *value, .left = NULL, .right = NULL }; 
		*a_root = new_root;
	}
	else if(*value < (*a_root) -> value) {
		_insert(&((*a_root) -> left), value);
	}
	else {
		_insert(&((*a_root) -> right), value); 
	}
}

void _destroy(BSTNode** a_root) {
	if(*a_root != NULL) {
		_destroy(&((*a_root) -> left)); 
		_destroy(&((*a_root) -> right));
		free(*a_root);
	//	*a_root = NULL;
	}
	 *a_root = NULL; 
}

void _fill_array_from_bst(int* array, int* j, BSTNode* a_root) {
	if(a_root != NULL) { 
		_fill_array_from_bst(array, j, (a_root) -> left);
		int ray = ((a_root) -> value);
		//printf("again: %d\n", array[*j]);
		//printf("asd %d\n", *j); 
		array[*j] = ray; 
		*j = *j + 1;
		//printf("n: %d\n", array[*j - 1]);
		//printf("array again: %d\n", ray);
		_fill_array_from_bst(array, j, (a_root) -> right); 
		}
}

BST create_bst(const int* array, int size) {
	BST	bst = { .root = NULL, .size = size };
	for(int i = 0; i < size; i++) {
		_insert(&(bst.root), &array[i]);
	}
	return bst;
}

void empty_bst(BST* a_bst) {
	_destroy(&((a_bst) -> root));
}

void tree_sort_array(int* array, size_t size) {
	BST bst = create_bst(array, size); 
	int j = 0;
	_fill_array_from_bst(array, &j, bst.root);
	empty_bst(&bst);
}

int _compare_fn_for_qsort(const void* o1, const void* o2) {
	return (*(int*)o1 - *(int*)o2);
}

void quick_sort_array(int* array, size_t size) {
	qsort(array, size, sizeof(array[0]), _compare_fn_for_qsort);
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
