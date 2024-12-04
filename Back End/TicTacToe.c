#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'


//prototypes
void initializeMap(char map[SIZE][SIZE]);
void displayMap(char map[SIZE][SIZE], int x, int y);
void move(int *x, int *y, char direction, char map[SIZE][SIZE]);
void BoxSelect(int x, int y, char map[SIZE][SIZE]);
void aiSelect(char map[SIZE][SIZE]);
int checkWin(char map[SIZE][SIZE]);
int checkTie(char map[SIZE][SIZE]);

int main (void)
{
    char map[SIZE][SIZE];
    int consoleRow = 0;
    int *conrowPtr = &consoleRow;
    int consoleCol = 0;
    int *concolPtr = &consoleCol;
    char direction = ' ';
    

    initializeMap(map);
    while(1)//loop only stops when game is finished
    {
    printf("Enter + to place your mark\n");
    displayMap(map, consoleRow, consoleCol);
    move(conrowPtr, concolPtr, direction, map);
    if (checkWin(map) || checkTie(map)) 
    {
        break;
    }
    }
    printf("\nThank you for playing :)\n\n");
    return 0;
}
//makes the board
void initializeMap(char map[SIZE][SIZE])//sets the map and plants the treasure
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            map[i][j] = EMPTY;
        }
    }
}

//displays the map >:D
void displayMap(char map[SIZE][SIZE], int x, int y)
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(i == x && j == y)
            {
            printf("[P] ");//prints the P wherever the player moves
            }
            else
            {
            printf("[%c] ", map[i][j]);
            }
        }
        printf("\n");
    }
}

//moves the player >:D
void move(int *x, int *y, char direction, char map[SIZE][SIZE])
{
    char initialdirection; // test direction to make sure they pick one of my options 
    while(1)
    {
    
    printf ("Enter direction (U/D/L/R): ");//prompt
    scanf("%c", &initialdirection);
    getchar();//cleans scanf up
    if(initialdirection == 'U' ||initialdirection == 'D' ||initialdirection == 'L'|| initialdirection == 'R')
    {
        direction = initialdirection;
        break;
    }
    else if(initialdirection == '+')
    {
        BoxSelect(*x, *y, map);
        break;
    }
    else
    {
        printf(" invalid input. please try agiain\n");
    }
    }
    if(direction == 'U')
    {
        *x -= 1;
    }else if (direction == 'D')
    {
        *x += 1;
    }else if (direction == 'R')
    {
        *y += 1;
    }else if (direction == 'L')
    {
        *y -= 1;
    } 
    if(*x <= SIZE && *x >= 0)// keeps x in bounds
    {
        //yay :)
    }
    else
    {
        if (*x < 0)
        {
            *x += 1;
        }
        else
        {
            *x -= 1;
        }
    }
    if(*y <= SIZE && *y >= 0)//keeps y in bounds
    {
        //yay :)
    } 
    else
    {
        if (*y < 0)
        {
            *y += 1;
        }
        else
        {
            *y -= 1;
        }
    }
}
void BoxSelect(int x, int y, char map[SIZE][SIZE])//makes sure user choses empty space and checks for a tie
{
    //only places if user chose an empty space
    while(1)
    {
        if(map[x][y] == EMPTY)
        {
            map[x][y] = PLAYER;
            break;
        }
        else
        {
            printf("the selected box is already taken.");
            return;
        }
    }
    if (checkWin(map)) 
    {
            displayMap(map, -2, -2); // Removes player marker
            printf("Player wins!\n");
            return;
    }

    if(checkTie(map) == 1)
    {
    printf("well... you seem to have tied.");
    return;
    }

    aiSelect(map);
    if (checkWin(map)) 
    {
            displayMap(map, -2, -2); // Removes player marker
            printf("AI wins :(\n");
            return;
    }

    if(checkTie(map) == 1)
    {
    printf("well... you seem to have tied.");
    return;
    }

}
void aiSelect(char map[SIZE][SIZE]) {
    //try to win
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (map[i][j] == EMPTY) {
                map[i][j] = AI;
                if (checkWin(map)) {
                    return;
                }
                map[i][j] = EMPTY;
            }
        }
    }
    
    //block player from winning
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (map[i][j] == EMPTY) {
                map[i][j] = PLAYER;
                if (checkWin(map)) {
                    map[i][j] = AI;
                    return;
                }
                map[i][j] = EMPTY;
            }
        }
    }
    
    //make a random move
    while (1) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if (map[i][j] == EMPTY) {
            map[i][j] = AI;
            return;
        }
    }
}
int checkWin(char map[SIZE][SIZE]) 
{
    // Check rows columns and diagonals
    for (int i = 0; i < SIZE; i++) 
    {
        if (map[i][0] != EMPTY && map[i][0] == map[i][1] && map[i][1] == map[i][2])
        {
            return 1;
        }
        if (map[0][i] != EMPTY && map[0][i] == map[1][i] && map[1][i] == map[2][i]) 
        {
            return 1;
        }
        if (map[0][0] != EMPTY && map[0][0] == map[1][1] && map[1][1] == map[2][2]) 
        {
            return 1;
        }
        if (map[0][2] != EMPTY && map[0][2] == map[1][1] && map[1][1] == map[2][0]) 
        {
            return 1;
        }
    }
    return 0;
}
int checkTie(char map[SIZE][SIZE])
{
    int markCount = 0;

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(map[i][j] != EMPTY)
            {
                markCount += 1;
            }
        }
    }
    if(markCount == 9) //(sizeof(map)/sizeof(map[0])))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* if(checkTie)
{
    printf("well... you seem to have tied."); return;
} */