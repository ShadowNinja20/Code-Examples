#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "huffman.h"

static int _compare_fn(const void* o1, const void* o2) {
	const TreeNode* tree1 = o1;
	const TreeNode* tree2 = o2;
	if(((tree1 -> frequency) - ((tree2) -> frequency)) != 0) {
		return ((tree1) -> frequency - (tree2) -> frequency);
	}
	else {
		return ((int)(tree1 -> character) - (int)(tree2 -> character));
	}
}

Node* make_huffman_pq(Frequencies freqs) {
	Node* huffman_node = NULL;
	for(int i = 0; i < 256; i++) {
		if(freqs[i] > 0) {
			TreeNode* value = malloc(sizeof(*value));
			*value = (TreeNode) { .character = (char)i, .frequency = freqs[i], .left = NULL, .right = NULL };
			pq_enqueue(&huffman_node, value, _compare_fn);
		}
	}
	return huffman_node;
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
