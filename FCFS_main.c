#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int main() {
    FILE* csvfile = fopen("input.csv", "r"); // 입력 CSV 파일
    int process_count = 0; // process의 개수 -> 평균반환시간을 구하기 위함
    int current_time = 0; // 현재 시간
    int total_time = 0; // 반환시간의 총합 -> 평균반환시간을 구하기 위함

    if (csvfile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    FILE* outputfile = fopen("FCFS_output.csv", "w+"); // 출력 CSV 파일

    if (outputfile == NULL) {
        printf("Failed to open the output file.\n");
        fclose(csvfile);
        return 1;
    }

    queue* ready_queue = init_queue(); // 준비 큐 초기화

    // CSV 파일에서 프로세스 정보 읽어오기
    data current_process;
    current_process.entry_time = 0; // entry_time 0으로 초기화
    while ((current_process = csv_read(csvfile, current_process.entry_time)).process_id != -1) {
        // 현재 프로세스의 진입 시간을 설정하고, 준비 큐에 추가
        enqueue(ready_queue, current_process);
    }
    printf("Process_id    priority    computing_time  turn_around time\n");
    // FCFS 스케줄링 실행
    while (1) {
        // 준비 큐에서 다음 프로세스 추출
        data running_process = dequeue(ready_queue);
        // 우선순위가 0보다 작으면 큐가 비어있는 상태
        if (running_process.priority < 0) {
            break;
        }

        // 프로세스 실행 (computing_time 만큼 시간 경과)
        if (running_process.process_id != 0) {
            current_time += running_process.computing_time;
        }

        // 결과를 출력 파일에 기록
        if (running_process.process_id != 0) {
            int ta_time = current_time - running_process.entry_time;
            csv_write(outputfile, running_process, ta_time);
            total_time += ta_time;
            process_count++;
        }
    }
    double FCFS_nomalized_ATAT = nomalized_ATAT(total_time, process_count);
    printf("FCFS_평균반환시간 = %.2f\n", FCFS_nomalized_ATAT); // 소수점 2자리까지 출력

    fclose(csvfile);
    fclose(outputfile);
    free(ready_queue);
    return 0;
}
