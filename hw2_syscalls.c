#include <linux/sched.h>


int sys_is_short(pid_t pid) {
	task_t* p = find_task_by_pid(pid);
	if(!p){
		return -3; // the value of ESRCH
	}
	if(p->sched_param == SCHED_SHORT){
		return 1; 
	}else if(p->sched_param == SCHED_OVRD_SHORT){
		return 0;
	}else{
		return -22;   //the value of EINVAL
	}

}


int sys_short_remaining_time(pid_t pid) {
	task_t* p = find_task_by_pid(pid);
	if(!p){
		return -3; // the value of ESRCH
	}
	if(p->policy == SCHED_SHORT){
		
		return p->time_slice* HZ / 1000;  
	}else if(p->policy == SCHED_OVRD_SHORT){
		
		return p->time_slice* HZ / 1000;  
	}else{
		return -22;   //the value of EINVAL
	}
}


int sys_short_place_in_queue(pid_t pid) {
	task_t* p = find_task_by_pid(pid);
	if(!p){
		return -3; // the value of ESRCH
	}
	if(p->policy == SCHED_SHORT){
		
		
	}else if(p->policy == SCHED_OVRD_SHORT){
		
		
	}else{
		return -22;   //the value of EINVAL
	}
}

