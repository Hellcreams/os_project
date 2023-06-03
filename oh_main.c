#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int spn(data new, data old) {
	long x, y;
	x = old.computing_time;
	y = new.computing_time;

	if(x > y) return -1;
	else if(x == y) return 0;
	else return 1;
}

int hrrn(data new, data old, int time){
	double x, y;
	x = (time - old.entry_time + old.computing_time) / (double) old.computing_time;
	y = (time - new.entry_time + new.computing_time) / (double) new.computing_time;

	if(x > y) return -1;
	else if(x == y) return 0;
	else return 1;
}

int main(int argc, char *argv[]) {
	data buffer;
	FILE *fr, *fw;
	int now_time, interval_time;
	node *process_tree = NULL;
	char *output_filename;
	
	// 리눅스 환경에서 실행할 때 "./a.out [csv파일 이름] [시간]"으로 입력해야 실행됨
	if(argc < 3 || argc > 4) return 1;
	now_time = 0;
	interval_time = atoi(argv[2]);
	
	if(argc == 4) output_filename = argv[3];
	else output_filename = "out.csv";

	fr = fopen(argv[1], "r"); // 읽기 전용 파일
	fw = fopen(output_filename, "w"); // 쓰기 전용 파일
	
	while (1) {
		buffer = csv_read(fr, now_time);
		printf("%d,%d,%ld,%ld\n", buffer.process_id, buffer.priority,
				buffer.computing_time, buffer.entry_time);
		if (buffer.process_id < 0) {
			if (buffer.priority == -1) continue;
			else break;
		}
		insert_node(&process_tree, buffer, hrrn);
	}
	
	while (1){
		buffer = pop_min_node(&process_tree);
		if (buffer.process_id < 0) break;
		csv_write(fw, buffer, now_time);
	}

	fclose(fr);
	fclose(fw);

	return 0;
}
