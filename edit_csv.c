#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"
#define MAX_size 1024

data csv_read(FILE *csvfile, int e_time) {
	char *p;
	int ary[4] = {0,0,0,0};
	int cnt, i;
	char str_tmp[MAX_size];
	data d;

	if (csvfile == NULL || feof(csvfile)) {
		data t = {-1, 0, 0, 0};
		return t;
	}
	fgets(str_tmp, MAX_size, csvfile);
	
	cnt = 0;
	p = strtok(str_tmp, ",");	
	
	while (p != NULL) {
		ary[cnt] = atoi(p);
		cnt++;
		p = strtok(NULL, ",");
	}
	
	if(ary[0] == -1) {
		data t = {-1, 0, 0, 0};
		return t;
	}

	d.process_id = ary[1];
	d.priority = ary[2];
	d.computing_time = ary[3];
	d.entry_time = e_time;

	return d;
}

void csv_write(FILE *csvfile, data d, int ta_time) {
	fprintf(csvfile, "%d,%d,%ld,%d\n", 
			d.process_id, d.priority, d.computing_time, ta_time);
}
