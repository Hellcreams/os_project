#include <stdio.h>
#include "stack.h"

int main() {
	stack *ss;
	init(ss);
	push(ss, 1);
	printf("c\n");
	printf("%d", pop(ss));
	printf("%d", pop(ss));
}
