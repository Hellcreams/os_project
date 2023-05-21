#include <stdio.h>
#include <stdlib.h>
#include "project.h"

node* init_node(data d) {
	node *new_node = malloc(sizeof(node));
	new_node->buf = d;
	new_node->left_node = NULL;
	new_node->right_node = NULL;
	return new_node;
}

void insert_node(node **root_node, data d, int (*function)(data a, data b)) {
	node **c_node;

	for(c_node = root_node; *c_node != NULL;) {
		if(function(d, (*c_node)->buf) < 0)
			c_node = &((*c_node)->left_node);
		else
			c_node = &((*c_node)->right_node);
	}

	*c_node = init_node(d);
}

data pop_min_node(node** root_node) {
	data table;
	node **c_node, *x_node;
	
	// 트리에 아무것도 없는 경우
	if(*root_node == NULL) {
		data t = {-1, 0, 0, 0};
		return t;
	}

	for(c_node = root_node; (*c_node)->left_node != NULL; c_node = &((*c_node)->left_node));
	
	table = (*c_node)->buf;
	
	x_node = *c_node;
	if((*c_node)->right_node != NULL)
		*c_node = (*c_node)->right_node;
	else
		*c_node = NULL;
	free(x_node);

	return table;

}
