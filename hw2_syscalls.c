#include <linux/sched.h>

int sys_is_short(pid_t pid) {
	task_t* p = find_task_by_pid(pid);
	if(!p){
		return -3; // the value of ESRCH
	}
	if(p->policy == SCHED_SHORT&&p->overdue==0){
		return 1; 
	}else if(p->policy == SCHED_SHORT&&p->overdue==1){
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
	if(p->policy == SCHED_SHORT&&p->overdue==0){
		
		return p->time_slice* HZ / 1000;  
	}else if(p->policy == SCHED_SHORT&&p->overdue==1){
		
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
	int i=0,sum=0;
	struct list_head * pos;
	
	prio_array_t* array= p->array;
	list_t queue = array->queue;
		for(i=0;i<140;i++){
			queue = array->queue + i;
			list_for_each(pos,&(queue)){
				if(list_entry(pos, struct task_struct, run_list))->pid==pid){
					return sum;
				}
				sum++;
			}
			
		}
		return -10; // if it gets here then something is wrong
		
	
		
	}else{ //if we are here it means p is not a short or overdue short
		return -22;   //the value of EINVAL
	}
}

