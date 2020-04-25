// Assignment 1 20T1 COMP1511: Minesweeper
// minesweeper.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0 (2020-03-08): Assignment released.
// Version 1.0.1 (2020-03-08): Fix punctuation in comment.
// Version 1.0.2 (2020-03-08): Fix second line of header comment to say minesweeper.c

#include <stdio.h>
#include <stdlib.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2

// The size of the starting grid.
#define SIZE 8

// The possible command codes.
#define DETECT_ROW              1
#define DETECT_COL              2
#define DETECT_SQUARE           3
#define REVEAL_SQUARE           4
#define GAMEPLAY_MODE           5
#define DEBUG_MODE              6
#define REVEAL_RADIAL           7

// Add any extra #defines here.

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);
void gameplaymode(int minefield[SIZE][SIZE]);
void detectnumMineRow(int detectinput2,int minefield[SIZE][SIZE]); //scan the number of mines in a row.
void detectnumMineCol(int detectinput2, int minefield[SIZE][SIZE]); //scan the number of mines in a col.
void detectnumMineSquare(int detectinput2, int minefield[SIZE][SIZE]); //scan the number of mines in a square.
int revealsquare (int detectinput2, int minefield[SIZE][SIZE]); //scan the reveal square.
int NoMineInSquare(int row, int col, int minefield[SIZE][SIZE]); 
void DisplaynoMine(int row, int col, int minefield[SIZE][SIZE]);
int HaveMineInSquare(int row, int col, int minefield[SIZE][SIZE]);
// Place your function prototyes here (we always need prototypes above the main function).
int main(void){
    int numMines;
    int input1;
    int input2;
    int detectinput1;
    int detectinput2;
    int minefield[SIZE][SIZE];
    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");
    scanf("%d",&numMines);
    printf("Enter pairs:\n");
    int i = 0;
    while(i < numMines){
        scanf("%d",&input1);
        scanf("%d",&input2);
        minefield[input1][input2] = 2;
        i++;
    }
    //don't need int, because we already defined it.
    // TODO: Scan in the number of pairs of mines.
    // TODO: Scan in the pairs of mines and place them on the grid.

    printf("Game Started\n");
    print_debug_minefield(minefield);
    int n = 0;
        while(scanf("%d",&detectinput1) != -1 && n < 3){ 
            //scanf returns -1 if it scans command-D.
            if(detectinput1 == DETECT_ROW){
                scanf("%d",&detectinput2);
                detectnumMineRow(detectinput2,minefield);
                //scan the number of mines in a row.
            }else if(detectinput1 == DETECT_COL){
                scanf("%d",&detectinput2);
                detectnumMineCol(detectinput2,minefield);
                //scan the number of mines in a col.
            }else if(detectinput1 == DETECT_SQUARE){
                scanf("%d",&detectinput2);
                detectnumMineSquare(detectinput2,minefield); 
                //scan the number of mines in a square.     
            }else if(detectinput1 == GAMEPLAY_MODE){
                printf("Gameplay mode activated\n");
                printf(". .\n");
                printf("\n");
                printf("\\ /\n");
                gameplaymode(minefield[SIZE][SIZE]);
            }else if(detectinput1 == DEBUG_MODE){
                printf("Debug mode activated\n");
                print_debug_minefield(minefield);
            }
            n++;
        }
    printf("Help already used\n");
    scanf("%d",&detectinput1);
    if(detectinput1 == DEBUG_MODE){
        printf("Debug mode activated\n");
        print_debug_minefield(minefield);
        while(scanf("%d",detectinput1)!= -1){
            if(detectinput1 == REVEAL_SQUARE){
                if(revealsquare(detectinput2,minefield) == 1){
                    //This happens when the you detect the mine.
                    return 1;
                    //if return is any number in the main function, the program end. return 1 represents the incorrect program, while 0 represents the correct program.
                }
            //if the selected square has no adjacent mine, then show all squares.
            }
        }
        // TODO: Scan in commands to play the game until the game ends.
        // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
        // You should display the minefield after each command has been processed.
    }else if(detectinput1 == GAMEPLAY_MODE){
        printf("Gameplay mode activated\n");
        gameplaymode(minefield[SIZE][SIZE]);
        while(detectinput1 != -1){
            if(scanf("%d",detectinput1) == REVEAL_SQUARE){
                if(revealsquare(detectinput2,minefield) == 1){
                    //This happens when the you detect the mine.
                    return 1;
                    //if return is any number in the main function, the program end. return 1 represents the incorrect program, while 0 represents the correct program.
                }
            //if the selected square has no adjacent mine, then show all squares.
            }
        }
    }

// Set the entire minefield to HIDDEN_SAFE.
}

void initialise_field(int minefield[SIZE][SIZE]){
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}
void gameplaymode(int minefield[SIZE][SIZE]){
    int i = 0;
    while(i < SIZE){
        int j = 0;
        while(j < SIZE){
            minefield[i][j];
            j++;
            printf("## ");
        }
        i++;
        printf("\n");  
    }
}

// Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]){
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}


void detectnumMineRow(int detectinput2,int minefield[SIZE][SIZE]){
    int i = 0;
    int counter = 0;
    while(i < SIZE){
        if(minefield[detectinput2][i] == 2){
            counter++;
        }
        i++;
    }
    printf("There are %d mines in row %d\n",counter,detectinput2);
    //it scans the number of mines in a row.
}

void detectnumMineCol(int detectinput2, int minefield[SIZE][SIZE]){
    int j = 0;
    int counter = 0;
        while(j < SIZE){
            if(minefield[j][detectinput2] == 2){
                counter++;
            }
            j++;
        }
        printf("There are %d mines in column %d\n",counter,detectinput2);
}

void detectnumMineSquare(int detectinput2, int minefield[SIZE][SIZE]){
    int row;
    row = detectinput2;
    int col;
    int size;
    scanf("%d",&col);
    scanf("%d",&size);
    int counter = 0;
    int i = row - 1;
    while(i <= row + 1){
        int j = col - 1;
        while (j <= col + 1){
            if(minefield[i][j] == 2){
                counter++;
            }
            j++;
        }
        i++;
    }
    printf("There are %d mine(s) in the square centered at row %d, column %d of size %d\n",counter,row,col,size);
}

int revealsquare(int detectinput2, int minefield[SIZE][SIZE]){
    int row;
    int col;
    row = detectinput2;
    //here we only change the left side, make the left side equals to the right side.
    scanf("%d",&row);
    scanf("%d",&col);
    if(minefield[row][col] == 2){
        printf("You lost!\n");
        print_debug_minefield(minefield);
        return 1;
        //This happens when the you detect the mine.
    }else if(
        NoMineInSquare(row, col, minefield)
        // minefield[row - 1][col - 1] != 2
        // && minefield[row][col - 1] != 2
        // && minefield[row + 1][col - 1] != 2
        // && minefield[row - 1][col] != 2
        // && minefield[row][col] != 2
        // && minefield[row + 1][col] != 2
        // && minefield[row - 1][col + 1] != 2
        // && minefield[row][col + 1] != 2
        // && minefield[row + 1][col + 1] != 2
    ){
        DisplaynoMine(row, col, minefield);
        print_debug_minefield(minefield);
        // minefield[row - 1][col - 1] = 0;
        // minefield[row][col - 1] = 0;
        // minefield[row + 1][col - 1] = 0;
        // minefield[row - 1][col] = 0;
        // minefield[row][col] = 0;
        // minefield[row + 1][col] = 0;
        // minefield[row - 1][col + 1] = 0;
        // minefield[row][col + 1] = 0;
        // minefield[row + 1][col + 1] = 0;
        // print_debug_minefield(minefield);
    }else if(
        !NoMineInSquare(row,col,minefield)
    ){
        minefield[row][col] = 0;
        print_debug_minefield(minefield);
    }
    else{
        print_debug_minefield(minefield);
    }
    return 0;
    //if there's return integer, has to use int instead of void. At the moment when we specify int, we need return integer.
}
int NoMineInSquare(int row, int col, int minefield[SIZE][SIZE]){
    int i = row - 1;
    int there_is_no_mine = 1;
        while(i <= row + 1){
            int j = col - 1;
            while(j <= col + 1){
                if(minefield[i][j] == 2){
                    there_is_no_mine = 0;
                }
                j++;
            }
            i++;
        }
    return there_is_no_mine;
    //return 0 means there's no mine, return 1 means there's a mine.
    //return 1 indicates that the condition is not true.
}

void DisplaynoMine(int row, int col, int minefield[SIZE][SIZE]){
    int i = row - 1;
    while(i <= row + 1){
        int j = col - 1;
        while(j <= col + 1){
            minefield[i][j] = 0;
            j++;
        }
        i++;
    }
}