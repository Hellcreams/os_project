#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int now_time;

int spn(data new, data old){
	int x, y;
	x = old.computing_time;
	y =  new.computing_time;

	if(x > y) return -1;
	else if(x == y) return 0;
	else return 1;
}

int main(int argc, char *argv[]) {
	data buffer;
	data write_buffer = {-1, 0, 0, 0};
	FILE *fr, *fw;
	int interval_time, next_time, processed_time;
	node *process_tree = NULL;
	char *output_filename;
	
	// 리눅스 환경에서 실행할 때 "./a.out [csv파일 이름] [시간] [*outfile 이름]"으로 입력해야 실행됨
	if(argc < 3 || argc > 4) {
		fprintf(stderr, "error, args = %d\n", argc);
		return 1;
	}
	now_time = 0; next_time = 0; processed_time = 0;
	interval_time = atoi(argv[2]);
	
	if(argc == 4) output_filename = argv[3];
	else output_filename = "out.csv";

	fr = fopen(argv[1], "r"); // 읽기 전용 파일
	fw = fopen(output_filename, "w"); // 쓰기 전용 파일
	
	while (1) {
		while (1) {
			buffer = csv_read(fr, now_time);
			// printf("%d,%d,%ld,%ld\n", buffer.process_id, buffer.priority,
			// 		buffer.computing_time, buffer.entry_time);
			if (buffer.process_id < 0) break;
			insert_node(&process_tree, buffer, spn);
		}

		next_time = next_time + interval_time;
		if (buffer.priority == -3) next_time = 999999999;
		
		while (1) {
			if (write_buffer.process_id == -1) 
				write_buffer = pop_min_node(&process_tree);
			if (now_time + write_buffer.computing_time - processed_time > next_time) {
				processed_time = processed_time + next_time - now_time;
				now_time = next_time;
				break;
			}
			if (write_buffer.process_id == -1) break;
			now_time = now_time + write_buffer.computing_time - processed_time;
			processed_time = 0;
			csv_write(fw, write_buffer, now_time);
			write_buffer.process_id = -1;
		}
		if (buffer.priority == -3) break;
	}
	

	fclose(fr);
	fclose(fw);

	return 0;
}
