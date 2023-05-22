#include <stdio.h>
#include "project.h"

int main(int argc, char *argv[]) {
	data buffer;
	FILE *fr, *fw;
	
	// 오류 검증
	// 리눅스 환경에서 실행할 때 "./a.out [csv파일 이름]"으로 입력해야 실행됨
	if(argc < 2) {
		fprintf(stderr, "Too few arguments. File of CSV name required.\n");
		return 1;
	}
	else if (argc > 2) {
		fprintf(stderr, "Too many arguments. Only file of CSv name required.\n");
		return 1;
	}

	fr = fopen(argv[1], "r"); // 읽기 전용 파일
	fw = fopen("out.csv", "w"); // 쓰기 전용 파일

	// 파일 읽어오기 예시 코드
	/*
	while (!feof(fr)) {
		buffer = csv_read(fr, 9);
		printf("%d,%d,%ld,%ld\n", buffer.process_id, buffer.priority,
				buffer.computing_time, buffer.entry_time);
		if (buffer.process_id > 1) 
			csv_write(fw, buffer, 7);
	}
	*/

	/* 
	 * 이 칸에 실행할 코드를 입력하세요.
	 * 각종 함수에 대한 설명은 헤더 파일 project.h를 참고하세요.
	 */
	
	fclose(fr);
	fclose(fw);
}
