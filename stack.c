#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *init_stack() {
	stack *Stack = malloc(sizeof(stack));
	Stack->top = malloc(sizeof(int));
	*(Stack->top) = -1;
	return Stack;
}

int is_full(stack *Stack) {
	if (*(Stack->top) >= STACK_SIZE -1) return 1;
	else return 0;
}

int is_empty(stack *Stack) {
	if (*(Stack->top) == -1) return 1;
	else return 0;
}

int push(stack *Stack, int data) {
	if (!is_full(Stack)) {
		Stack->buf[++(*(Stack->top))] = data;
		return 0;
	}
	return -1;
}

int pop(stack *Stack) {
	if (!is_empty(Stack)) {
		return Stack->buf[(*(Stack->top))--];
	}
	fprintf(stderr, "error : Failed to pop because the stack is EMPTY!\n");
	return 0;
}
