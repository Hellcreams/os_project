#define STACK_SIZE 512
#define MAX_QUEUE_SIZE 512

// 공통
typedef struct buf {
	int process_id;
	int priority;
	long computing_time;
	long entry_time;
} data;

// stack
typedef struct _stack {
	data buf[STACK_SIZE];
	int top;
} stack;

stack* init_stack();

int is_full(stack*);

int is_empty(stack*);

int push(stack*, data);

data pop(stack*);

// tree
typedef struct _tree_node {
	data buf;
	struct _tree_node *left_node;
	struct _tree_node *right_node;
} node;

void insert_node(node**, data, int(*)(data, data));

data pop_min_node(node**);

// edit_csv
data csv_read(FILE *, int);

void csv_write(FILE *, data, int);

double nomalized_ATAT(int, int);

// queue
typedef struct _queue {
	data buf[MAX_QUEUE_SIZE];
	int front;
	int rear;
} queue;

queue* init_queue();

int is_fullqueue(queue*);

int is_emptyqueue(queue*);

int enqueue(queue*, data);

data dequeue(queue*);
