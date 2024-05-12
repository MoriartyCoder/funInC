#include "thread.h"

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create() 
static void* myThreadFun(void *p_vargp) { 
	sleep(1); 
	printf("Printing GeeksQuiz from Thread \n"); 
	return NULL; 
} 

int main() { 
	pthread_t thread_id; 
	printf("Before Thread\n");

	pthread_create(&thread_id, NULL, myThreadFun, NULL); 
	pthread_join(thread_id, NULL); 

	printf("After Thread\n"); 
	exit(0); 
}

