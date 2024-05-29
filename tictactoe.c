#include "main.h"
#include <assert.h>

#define SIZE 3
#define STD " "
#define X "X"
#define O "O"

typedef struct FIELD {
  char field[SIZE][SIZE][1 + 1];
} FIELD;


static void printField(FIELD *p_field) {
  int i = 0;
  int o = 0;

  printf("   ");
  for(i = 0; i < SIZE; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  for(i = 0; i < SIZE; i++) {
    printf("%d  ", i + 1);

    for(o = 0; o < SIZE; o++) {
      printf("%s", p_field->field[i][o]);     

      if(o < SIZE - 1) {
        printf("|");
      }

    }

    // Start new line to add -------
    printf("\n");

    // Prespacing
    printf("   ");

    for(o = 0; o < (SIZE + SIZE - 2); o++) {
      printf("-");
    }
    printf("\n");
  }

}

static int checkForWinner(FIELD *p_field) {
  int  x            = 0;
  int  y            = 0;
  int  result       = 0; // Set to no winner
  int  iCounter     = 0;
  char cCmp[1 + 1]  = "";

  for(result = 1; result < 3; result++) {
    if(result == 1) {
      sprintf(cCmp, X);
    } else if(result == 2){
      sprintf(cCmp, O);
    }

    // Vertical check
    for(x = 0; x < SIZE; x++) {
      iCounter = 0;
      for(y = 0; y < SIZE; y++) {
        if(strcmp(p_field->field[y][x], cCmp) == 0) {
          iCounter++;
        } else {
          break;
        }
      }

      if(iCounter == SIZE) {
        return result;
      }
    }

    // Horizontal check
    for(y = 0; y < SIZE; y++) {
      iCounter = 0;
      for(x = 0; x < SIZE; x++) {
        if(strcmp(p_field->field[y][x], cCmp) == 0) {
          iCounter++;
        } else {
          break;
        }
      }

      if(iCounter == SIZE) {
        return result;
      }
    }


    // Diagonal left top to right down
    for(y = 0; y < SIZE; y++) {
      x = y;
      if(strcmp(p_field->field[y][x], cCmp) == 0) {
        iCounter++;
      } else {
        break;
      }

      if(iCounter == SIZE) {
        return result;
      }
    }

    // Diagonal left top to right down
    for(x = 0; x < SIZE; x++) {
      y = SIZE - 1 - x;
      if(strcmp(p_field->field[y][x], cCmp) == 0) {
        iCounter++;
      } else {
        break;
      }

      if(iCounter == SIZE) {
        return result;
      }
    }
  }

  // No winner
  return 0;
}

static void genTestGame(FIELD *p_field, int iGame) {

  switch(iGame) {
    case 1:
      for(int i = 0; i < SIZE; i++) {
        sprintf(p_field->field[2][i], O);
      }
      break;
    case 2: 
      for(int i = 0; i < SIZE; i++) {
        sprintf(p_field->field[i][1], X);
      }
      break;
    case 3: 
      for(int i = 0; i < SIZE; i++) {
        sprintf(p_field->field[i][i], X);
      }
      break;
    case 4: 
      int o = 0;
      for(int i = 0; i < SIZE; i++) {
        o = SIZE - 1 - i;
        sprintf(p_field->field[o][i], X);
      }
      break;
  };

}

static char* getPlayerSymbol(const int iPlayer) {
  static char cPlayer[1 + 1] = "";

  if(iPlayer % 2 == 1) {
    sprintf(cPlayer, X);
  } else {
    sprintf(cPlayer, O);
  }

  return cPlayer;
}

static void announcePlayer(const int iPlayer) {
  printf("Turn of Player %s\n", getPlayerSymbol(iPlayer));
}

static void getPlayerInput(FIELD *p_field) {
  int i = 0;
  int iInputs[] = {0, 0};

  char input[1 + 1]; // Annahme: Die Eingabe ist kürzer als 100 Zeichen
  int number;


  while(i <= 1) {
    if(i == 0) {
      printf("Enter y-coordinate: ");
    } else {
      printf("Enter x-coordinate: ");
    }


    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[1] = '\0';
        printf("ERROR is here!\n");
        if(input[0] < '0' || input[0] > '9' || input[0] > SIZE) {
          continue;
        }

        // Konvertiere den String in einen Integer
        iInputs[i] = atoi(input);

        
    } else {
        printf("Fehler beim Lesen der Eingabe.\n");
    }

  }
}

extern void tictactoe() { 
  FIELD field;
  int iPlayer = 0;

  if(SIZE % 2 == 0) {
    printf("FIELDSIZE NOT VALID\n");
    exit(100);
  }

  for(int i = 0; i < SIZE; i++) {
    for(int o = 0; o < SIZE; o++) {
      field.field[i][o][0] = 0;     
      sprintf(field.field[i][o], STD);     
    }
  }

  // genTestGame(&field, 3);
  // printf("::: %d\n", checkForWinner(&field));

  while(checkForWinner(&field) == 0 && iPlayer < 15) {
    iPlayer++;

    announcePlayer(iPlayer);
    printField(&field);
    getPlayerInput(&field);
  }


  printf("END!\n");
}

