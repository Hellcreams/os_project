#include <stdio.h>
#include "project.h"

int how(data a, data b) {
	int x = a.computing_time;
	int y = b.computing_time;

	if (x > y)
		return -1;
	else if (x == y)
		return 0;
	else
		return 1;
}

int main(int argc, char *argv[]) {
	data* buffer;
	// stack
	stack *ss = init_stack(ss);

	push(ss, 1, 25, 80, 0);
	push(ss, 2, 15, 40, 0);
	push(ss, 3, 8, 30, 0);
	
	printf("Id,Pr,Ct,Et\n");
	for(int i = 0; i < 3; i++) {
		buffer = pop(ss);
		printf("%d,%d,%ld,%ld\n", buffer->process_id, buffer->priority, 
				buffer->computing_time, buffer->entry_time);
	}
	
	data hello;
	printf("%ld\n", hello.computing_time);

	// tree
	data b;
	tree* what_tree = init_tree(how);

	insert_node(what_tree, 1, 25, 80, 0);
	insert_node(what_tree, 2, 15, 40, 0);
	insert_node(what_tree, 3, 8, 30, 0);

	printf("Id,Pr,Ct,Et\n");
	for(int i = 0; i < 3; i++) {
		b = pop_min_node(what_tree);
		printf("%d,%d,%ld,%ld\n", b.process_id, b.priority,
				b.computing_time, b.entry_time);
	}
}
