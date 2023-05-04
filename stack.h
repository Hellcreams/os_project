#define STACK_SIZE 512

typedef struct _stack {
	int buf[STACK_SIZE];
	int top;
} stack;

stack* init_stack();

int is_full(stack*);

int is_empty(stack*);

int push(stack*, int);

int pop(stack*);

