#include <stdio.h>
#include "stack.h"

int main() {
	stack *ss = init_stack(ss);
	push(ss, 1);
	printf("%d\n", pop(ss));
	printf("%d\n", pop(ss));
}
