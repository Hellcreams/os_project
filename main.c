#include <stdio.h>
#include "project.h"

int how(data a, data b) {
	printf("what\n");
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
	data buffer;
	// stack
	stack *ss = init_stack(ss);
	
	data processes[3] = {{1, 25, 80, 0}, {2, 15, 40, 0}, {3, 8, 30, 0}}; 
	
	for (int i = 0; i < 3; i++)
		push(ss, processes[i]);
	
	printf("Id,Pr,Ct,Et\n");
	for(int i = 0; i < 3; i++) {
		buffer = pop(ss);
		printf("%d,%d,%ld,%ld\n", buffer.process_id, buffer.priority, 
				buffer.computing_time, buffer.entry_time);
	}

	// tree
	node* what_tree = NULL; 
	data b;
	for(int i = 0; i < 3; i++) {
		printf("inserting...[%d]\n", i);
		what_tree = insert_node(what_tree, processes[i], how);
		if (what_tree == NULL)
			printf("what_tree is NULL!");
	}

	printf("Id,Pr,Ct,Et\n");
	for(int i = 0; i < 3; i++) {
		printf("getting...[%d]\n", i);
		b = get_min_node(what_tree);
		printf("%d,%d,%ld,%ld\n", b.process_id, b.priority,
				b.computing_time, b.entry_time);
		what_tree = remove_min_node(what_tree);
	}
}
