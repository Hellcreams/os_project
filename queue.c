#include <stdio.h>
#include <stdlib.h>
#include "project.h"

queue* init_queue() {
	queue *Queue  = malloc(sizeof(queue));
	Queue -> front = -1;
	Queue -> rear = -1;
	return Queue;
}

int is_fullqueue(queue* Queue) {
	if (Queue->rear == MAX_QUEUE_SIZE - 1) return 1;
	else return 0;
}

int is_emptyqueue(queue* Queue) {
	if (Queue->front == Queue->rear) return 1;
	else return 0;
}

int enqueue(queue* Queue, data buf) {
	if (!is_fullqueue(Queue)) {
		Queue->buf[++(Queue->rear)] = buf;
		return 0;
	}
	return -1;
}

data dequeue(queue* Queue) {
	data buffer = { 0, -1, 0, 0 };
	if (!is_emptyqueue(Queue)) {
		buffer = Queue->buf[++(Queue->front)];
	}
	return buffer;
}
