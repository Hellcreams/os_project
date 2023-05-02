#include <stdio.h>
#include "stack.h"

int stack[STACK_SIZE];
int top = -1;

int is_full() {
	if (top >= STACK_SIZE -1) return 1;
	else return 0;
}

int is_empty() {
	if (top == -1) return 1;
	else return 0;
}

int push(int data) {
	if (!is_full()) {
		stack[++top] = data;
		return 0;
	}
	return -1;
}

int pop() {
	if (!is_empty()) {
		return stack[top--];
	}
	fprintf(stderr, "error : Failed to pop because the stack is EMPTY!\n");
	return 0;
}



