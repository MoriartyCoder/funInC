#include "thread.h"

#define RANGE 7
#define STEP 1500
#define TYPE long 

typedef struct TPARA {
  TYPE iStart;
  TYPE iEnd;
} TPARA;

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create() 
static void* myThreadFun(void *p_arg) {
  TPARA *p_para = (TPARA*)p_arg;
  TYPE i        = 0;
  TYPE p        = 0;
  int bPrime    = 1;

  // Skip an even number
  if(p_para->iStart % 2 == 0) {
    p_para->iStart++;
  }

  for(i = p_para->iStart; i <= p_para->iEnd; i += 2) {
    bPrime = 1;

    for(p = 2; p * p <= i; p++) {
      if(i % p == 0) {
        bPrime = 0;
        break;
      }
    }

    if(bPrime) {
      printf("%5ld - %5ld : %5ld\n", p_para->iStart, p_para->iEnd, i);
    }
  }

  pthread_exit(NULL);
  return NULL; 
} 

int main() { 
  pthread_t thread_ids[RANGE]; 
  TPARA     threads_parameter[RANGE];

  for(int i = 0; i < RANGE; i++) {
    threads_parameter[i].iStart = MAX(i * STEP + 1, 3);
    threads_parameter[i].iEnd = threads_parameter[i].iStart + STEP;

    pthread_create(&thread_ids[i], NULL, myThreadFun, &threads_parameter[i]); 
  }

  for(int i = 0; i < RANGE; i++) {
    pthread_join(thread_ids[i], NULL);
  }

  exit(0); 
}

