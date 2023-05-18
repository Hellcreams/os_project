#include <stdio.h>
#include <stdlib.h>
#include "project.h"

node* insert_node(node *root_node, data d, int (*function)(data a, data b)) {
	// 위치 찾기
	int x;
	node *p_node, *c_node;

	for(c_node = root_node; c_node != NULL;) {
		printf("hello\n");
		p_node = c_node;
		if(x = function(d, c_node->buf) < 0)
			c_node = c_node->left_node;
		else
			c_node = c_node->right_node;
		printf("bye\n");	
	}

	// 

	// 값 넣기
	c_node = malloc(sizeof(data));
	c_node->buf = d;
	if (x < 0) p_node->left_node = c_node;
	else p_node->right_node = p_node;

	return root_node;
}

node* remove_min_node(node* root_node) {
	data table;
	node *p_node, *c_node;
	
	// 트리에 아무것도 없는 경우
	if(root_node == NULL)
		return NULL;

	for(c_node = root_node; c_node->left_node != NULL; c_node = c_node->left_node)
		p_node = c_node;

	if(p_node == NULL)
		root_node = c_node->right_node;
	else
		p_node->left_node = c_node->right_node;
	free(c_node);
	return root_node;
}

data get_min_node(node* root_node) {
	data table;
	node *c_node;
	
	// 트리에 아무것도 없는 경우
	if(root_node == NULL) {
		data t = {-1, 0, 0, 0};
		return t;
	}

	for(c_node = root_node; c_node->left_node != NULL; c_node = c_node->left_node);
	return c_node->buf;
}
