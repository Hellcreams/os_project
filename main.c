#include <stdio.h>
#include "project.h"

int how(data new, data old) {
	int n = new.computing_time;
	int o = old.computing_time;
	if (n < o)
		return -1;
	else if (n == 0)
		return 0;
	else
		return 1;
}

int main(int argc, char *argv[]) {
	data buffer;
	// stack
	stack *ss = init_stack(ss);
	
	data processes[3] = {{1, 25, 30, 0}, {2, 15, 10, 0}, {3, 8, 20, 0}}; 
	
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
		insert_node(&what_tree, processes[i], how);
	}

	printf("Id,Pr,Ct,Et\n");
	for(int i = 0; i < 3; i++) {
		printf("getting...[%d]\n", i);
		b = pop_min_node(&what_tree);
		printf("%d,%d,%ld,%ld\n", b.process_id, b.priority,
				b.computing_time, b.entry_time);
	}
}
