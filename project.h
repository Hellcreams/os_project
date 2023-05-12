#define STACK_SIZE 512

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

int push(stack*, int, int, long, long);

data* pop(stack*);

// tree
typedef struct _tree_node {
	data buf;;
	struct _tree_node *left_node;
	struct _tree_node *right_node;
} node;

typedef struct _tree_head {
	int (*determinant)(data, data);		// 두 데이터를 비교해줄 함수
	node *root_node;
} tree;

void insert_node(tree*, int, int, long, long);

tree* init_tree(int (*)(data, data));

data pop_min_node(tree*);

void remove_tree(tree*);
