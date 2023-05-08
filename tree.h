typedef struct buf {
	int process_id;
	int priority;
	long computing_time;
} data;

typedef struct _tree_node {
	data buf;;
	struct _tree_node *left_node;
	struct _tree_node *right_node;
} node;

typedef struct _tree_head {
	int (*determinant)(data*, data*); // 두 데이터를 비교해줄 함수
	node *root_node;
} tree;

tree* init_tree(int (*)(data*, data*));

node* insert_node(tree*, int, int, long);

node* pop_min_node(tree*);

void remove_tree(tree*);
