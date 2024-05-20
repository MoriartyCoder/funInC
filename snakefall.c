#include "main.h"
#define RANGE 2

typedef struct TPARA {
  int left;
  int right;
  int up;
  int down;
  int exit;
} TPARA;

static void* myThreadFun(void *p_arg) {
  TPARA *p_para = (TPARA*)p_arg;
  (void) p_para;
  char c = '.';
  int  iC = 0;
  (void) iC;

  while(1){

    c = getchar();

    if(c == EOF) {
      break;
    }
    putchar(c);
  }
  /*
     while((c = getchar()) != EOF) {
     iC = (int)c;
     if(iC == p_para->up) {
     printf("UP");
     break;
     }

     }
   */
  pthread_exit(NULL);
  return NULL; 
} 

extern void snakefall() { 
  pthread_t thread_ids[RANGE]; 
  TPARA     threads_parameter[RANGE];

  memset(&threads_parameter, 0, sizeof(TPARA) * RANGE);
  
  threads_parameter[0].left  = (int)'a';
  threads_parameter[0].right = (int)'d';
  threads_parameter[0].up    = (int)'w';
  threads_parameter[0].down  = (int)'s';

  threads_parameter[1].left  = (int)'j';
  threads_parameter[1].right = (int)'l';
  threads_parameter[1].up    = (int)'i';
  threads_parameter[1].down  = (int)'k';

  for(int i = 0; i < RANGE; i++) {
    pthread_create(&thread_ids[i], NULL, myThreadFun, &threads_parameter[i]); 
  }

  for(int i = 0; i < RANGE; i++) {
    pthread_join(thread_ids[i], NULL);
  }
}
