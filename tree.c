#include <stdio.h>
#include <stdlib.h>
#include "project.h"

tree* init_tree(int (*function)(data, data)) {
	tree *tree_head = malloc(sizeof(tree));
	tree_head->determinant = function;

	return tree_head;
}

void insert_node(tree* tree_head, int pid, int prior, long c_time, long e_time) {
	node* new_node = malloc(sizeof(node));
	data table;
	table.process_id = pid;
	table.priority = prior;
	table.computing_time = c_time;
	table.entry_time = e_time;
	table = new_node->buf = table;
	
	node* c_data;
	for (c_data = tree_head->root_node; c_data->buf.computing_time != 0;) {
		if (tree_head->determinant(table, c_data->buf) < 0)
			c_data = c_data->left_node;
		else
			c_data = c_data->right_node;
	}
	c_data = new_node;
}

data pop_min_node(tree* tree_head) {
	data table;
	node *c_data, *tmp;

	// 트리에 아무 것도 없는 경우
	if (tree_head->root_node == NULL)
		return table;

	// 바로 왼쪽에 아무 것도 없는 경우
	if (tree_head->root_node->left_node == NULL) {
		table = tree_head->root_node->buf;
		if (tree_head->root_node->right_node != NULL) {
			tmp = tree_head->root_node->right_node;
			free(tree_head->root_node);
			tree_head->root_node = tmp;
		}
		else
			free(tree_head->root_node);
		return table;
	}

	// 일반적인 경우
	for (c_data = tree_head->root_node; c_data->left_node->left_node != NULL;)
		c_data = c_data->left_node;
	
	table = c_data->left_node->buf;
	if (c_data->left_node->right_node != NULL) {
		tmp = c_data->left_node->right_node;
		free(c_data->left_node);
		c_data->right_node = tmp;
	}
	else
		free(c_data->left_node);
	return table;
}

void remove_tree(tree* tree_head) {

}
