#include <stdio.h>
#include <stdlib.h>
#include "project.h"

stack *init_stack() {
	stack *Stack = malloc(sizeof(stack));
	Stack->top = -1;
	return Stack;
}

int is_full(stack *Stack) {
	if (Stack->top >= STACK_SIZE - 1) return 1;
	else return 0;
}

int is_empty(stack *Stack) {
	if (Stack->top == -1) return 1;
	else return 0;
}

int push(stack *Stack, int pid, int prior, long c_time, long e_time) {
	if (!is_full(Stack)) {
		(Stack->top)++;
		Stack->buf[(Stack->top)].process_id  = pid;
		Stack->buf[(Stack->top)].priority = prior;
		Stack->buf[(Stack->top)].computing_time = c_time;
		Stack->buf[(Stack->top)].entry_time = e_time;
		return 0;
	}
	return -1;
}

data* pop(stack *Stack) {
	data *buffer;
	buffer = malloc(sizeof(data));
	if (!is_empty(Stack)) {
		buffer->process_id = Stack->buf[(Stack->top)].process_id;
		buffer->priority = Stack->buf[(Stack->top)].priority;
		buffer->computing_time = Stack->buf[(Stack->top)].computing_time;
		buffer->entry_time = Stack->buf[(Stack->top)].entry_time;
		(Stack->top)--;
		return buffer;
	}

	free(buffer);
	return NULL;
}
