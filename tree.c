#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tree* init_tree(int (*function)(data*, data*)) {
	tree *tree_head = malloc(sizeof(tree));
	tree_head->determinant = function;

	return tree_head;
}

node* insert_node(tree* tree_head, int pid, int prior, long c_time) {
	data* table = malloc(sizeof(data));
	table->process_id = pid;
	table->priority = prior;
	table->computing_time = c_time;
	
	/*
	 * 여기부터 들어갈 방식 정하기...
	 */

	return NULL;
}

node* pop_min_node(tree* tree_head) {
	return NULL;
}

void remove_tree(tree* tree_head) {

}
