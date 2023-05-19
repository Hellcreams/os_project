#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_size 1024

void read() {
	char *p;
	int ary[4] = {0,0,0,0};
	int cnt, i;
	char str_tmp[MAX_size];
	
	FILE *csvfile = NULL;

	csvfile = fopen("text.csv", "r");

	if (csvfile != NULL) {
		while (!feof(csvfile)) {
			fgets(str_tmp, MAX_size, csvfile);
			//printf("%s", str_tmp);

			cnt = 0;
			p = strtok(str_tmp, ",");

			while (p != NULL) {
				ary[cnt] = atoi(p);
				cnt++;
				p = strtok(NULL, ",");
			
			}
			for (i = 0; i < cnt; i++) {
				printf("%d ", ary[i]);
			}
			printf("\n");
		}

	}
	fclose(csvfile);
}

int main() {
	read();
	return 0;
}