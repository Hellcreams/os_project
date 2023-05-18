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

int push(stack *Stack, data buf) {
	if (!is_full(Stack)) {
		(Stack->top)++;
		Stack->buf[(Stack->top)] = buf;
		return 0;
	}
	return -1;
}

data pop(stack *Stack) {
	data buffer =  {0, -1, 0, 0};
	if (!is_empty(Stack)) {
		buffer = Stack->buf[(Stack->top--)];
	}
	return buffer;
}
