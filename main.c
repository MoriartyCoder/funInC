#include "tictactoe.h"
#include "snakefall.h"


#define SNAKEFALL 1
#define TICTACTOE 2

#define CURRENT TICTACTOE 


int main(int argc, char *argv[]) { 

  int i = CURRENT;

  if(argc > 1) {
    printf("Number of arguments: %2d\n", argc);

    for(int o = 0; o < argc; o++) {
      printf("Argument %2d: %s\n", o + 1,argv[o]);
    }
  } else {
    printf("No arguments!\n");
  }
  printf("\n");

  switch(i) {
    case SNAKEFALL:
      snakefall();
      break;

    case TICTACTOE:
      tictactoe();
      break;

    default:
      printf("No Fun Found!");
      break;
  };

  exit(0); 
}

