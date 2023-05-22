#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"
#define MAX_size 1024

data read(FILE * csvfile) {
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
	printf("hello\n");
	
	cnt = 0;
	p = strtok(str_tmp, ",");	
	
	while (p != NULL) {
		ary[cnt] = atoi(p);
		cnt++;
		p = strtok(NULL, ",");
	}

	d.process_id = ary[0];
	d.priority = ary[1];
	d.computing_time = ary[2];
	d.entry_time = ary[3];

	return d;
}
