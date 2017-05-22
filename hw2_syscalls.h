#ifndef _HW2_SYSCALLS_H
#define _HW2_SYSCALLS_H



#include <errno.h>
#include <termios.h>
#include <stdlib.h>


#define SCHED_OTHER		0
#define SCHED_FIFO		1
#define SCHED_RR		2
#define SCHED_SHORT     5

typedef struct sched_param {
    int sched_priority, requested_time, sched_short_prio;
} sched_param_t;

int is_short(pid_t pid) {
	if(pid<0){
		errno = ESRCH;
		return -1;
	}
	int res = -1;
	__asm__(
		"int $0x80;"
		: "=a" (res)
		: "0" (243), "b" (pid)
		:"memory"
		);
	if (res < 0) {
		errno = (-res);
		return -1;
	}
	return res;
}


int short_remaining_time(pid_t pid) {
		if(pid < 0){
		errno = ESRCH;
		return -1;
	}
	int res = -1;
	__asm__(
		"int $0x80;"
		: "=a" (res)
		: "0" (244), "b" (pid)
		:"memory"
		);
	if (res < 0) {
		errno = (-res);
		return -1;
	}
	return res;
}


int short_place_in_queue(pid_t pid) {
	if(pid < 0){
		errno = ESRCH;
		return -1;
	}
	int res = -1;
	__asm__(
		"int $0x80;"
		: "=a" (res)
		: "0" (245), "b"(pid)
		:"memory"
		);
	if (res < 0) {
		errno = (-res);
		return -1;
	}
	return res;
}

#endif /*  HW2_SYSCALLS_H_ */
