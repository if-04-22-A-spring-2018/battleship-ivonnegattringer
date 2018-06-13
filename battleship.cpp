/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>

#include "battleship.h"
#define SIZE 10
static CellContent myField[SIZE][SIZE];
static CellContent enemyField[SIZE][SIZE];
static CellContent myGuesses[SIZE][SIZE];

void load_game(){
    FILE* myFile = fopen("battleship.my", "r");
    FILE* enemyFile = fopen("battleship.op", "r");

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            fread(&myField[i][j], 4, 1, myFile);
            fread(&enemyField[i][j], 4, 1, enemyFile);
            myGuesses[i][j] = Unknown;
        }
    }
    fclose(myFile);
    fclose(enemyFile);
}

CellContent get_shot(int row, int col){
    return row> -1 && row< SIZE && col>-1&&col<SIZE ? myField[row][col]: OutOfRange;
}

bool shoot(int row, int col){
    if(!(row> -1 && row< SIZE && col>-1&&col<SIZE ))return false;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if(row+i> -1 && row+i< SIZE && col+j>-1&&col+j<SIZE)myGuesses[row+i][col+j] = enemyField[row+i][col+j];
        }
    }
    return true;
}

CellContent get_my_guess(int row, int col){
    return row> -1 && row< SIZE && col>-1&&col<SIZE ? myGuesses[row][col]: OutOfRange;
}