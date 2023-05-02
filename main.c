#include <stdio.h>

int main() {
	push(1);
	push(2);
	push(3);
	for (int i = 0; i < 3; i++)
		printf("%d\n", pop());
}
