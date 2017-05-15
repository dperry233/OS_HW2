
#include <errno.h>
#include <termios.h>



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

