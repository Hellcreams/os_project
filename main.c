#include <stdio.h>
#include "stack.h"

int main() {
	stack *ss = init_stack(ss);
	data *buffer;

	push(ss, 1, 25, 80);
	push(ss, 2, 15, 40);
	push(ss, 3, 8, 30);
	
	printf("Id,Pr,Ct\n");
	for(int i = 0; i < 3; i++) {
		buffer = pop(ss);
		printf("%d,%d,%ld\n", buffer->process_id, buffer->priority, buffer->computing_time);
	}
}
