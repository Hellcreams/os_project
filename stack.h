#define STACK_SIZE 512

typedef struct buf {
	int process_id;
	int priority;
	long computing_time;
} data;

typedef struct _stack {
	data buf[STACK_SIZE];
	int top;
} stack;

stack* init_stack();

int is_full(stack*);

int is_empty(stack*);

int push(stack*, int, int, long);

data* pop(stack*);
