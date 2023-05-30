#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int main() {
    FILE* csvfile = fopen("input.csv", "r"); // �Է� CSV ����
    int process_count = 0; // process�� ���� -> ��չ�ȯ�ð��� ���ϱ� ����
    int current_time = 0; // ���� �ð�
    int total_time = 0; // ��ȯ�ð��� ���� -> ��չ�ȯ�ð��� ���ϱ� ����

    if (csvfile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    FILE* outputfile = fopen("FCFS_output.csv", "w+"); // ��� CSV ����

    if (outputfile == NULL) {
        printf("Failed to open the output file.\n");
        fclose(csvfile);
        return 1;
    }

    queue* ready_queue = init_queue(); // �غ� ť �ʱ�ȭ

    // CSV ���Ͽ��� ���μ��� ���� �о����
    data current_process;
    current_process.entry_time = 0; // entry_time 0���� �ʱ�ȭ
    while ((current_process = csv_read(csvfile, current_process.entry_time)).process_id != -1) {
        // ���� ���μ����� ���� �ð��� �����ϰ�, �غ� ť�� �߰�
        enqueue(ready_queue, current_process);
    }
    printf("Process_id    priority    computing_time  turn_around time\n");
    // FCFS �����ٸ� ����
    while (!is_emptyqueue(ready_queue)) {
        // �غ� ť���� ���� ���μ��� ����
        data running_process = dequeue(ready_queue);

        // ���μ��� ���� (computing_time ��ŭ �ð� ���)
        if (running_process.process_id != 0) {
            current_time += running_process.computing_time;
        }

        // ����� ��� ���Ͽ� ���
        if (running_process.process_id != 0) {
            csv_write(outputfile, running_process, current_time - running_process.entry_time);
            total_time += current_time - running_process.entry_time;
            process_count++;
        }
    }
    double FCFS_nomalized_ATAT = nomalized_ATAT(total_time, process_count);
    printf("FCFS_��չ�ȯ�ð� = %.2f\n", FCFS_nomalized_ATAT); // �Ҽ��� 2�ڸ����� ���

    fclose(csvfile);
    fclose(outputfile);

    return 0;
}