project.out: FCFS_main.c edit_csv.c queue.c tree.c project.h
	gcc FCFS_main.c edit_csv.c queue.c -o FCFS.out
	gcc SPN_main.c edit_csv.c tree.c -o SPN.out

