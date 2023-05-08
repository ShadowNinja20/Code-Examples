#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "sorts.h"

void _print_array(int* array, size_t size, const char* title) {
    printf("%s\n", title);
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int main(int argc, char* argv[]) {
    
    BST bst = create_bst((int[7]) { 5, 3, 1, 7, 2, 4, 6 }, 7);
    assert(bst.root        != NULL && bst.root->value        == 5);
    assert(bst.root->left  != NULL && bst.root->left->value  == 3);
    assert(bst.root->right != NULL && bst.root->right->value == 7);
    empty_bst(&bst);

    int array_1[] = { 5, 4, 10, 40, 2, 1, 7, 6, 3 };
    size_t size_1 = sizeof(array_1) / sizeof(*array_1);  
	_print_array(array_1, size_1, "Before tree sort");
    tree_sort_array(array_1, size_1);
    _print_array(array_1, size_1, "After tree sort");

    int array_2[] = { 1, 5, 7, 2, 7, 76, 23 };
    size_t size_2 = sizeof(array_2) / sizeof(*array_2);  
	_print_array(array_2, size_2, "Before qsort");
    quick_sort_array(array_2, size_2);
    _print_array(array_2, size_2, "After qsort");

    return EXIT_SUCCESS;
}
