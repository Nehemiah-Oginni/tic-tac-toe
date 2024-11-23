#include <stdio.h>
#define SIZE 3
#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

//prototypes
void initializeMap(char map[SIZE][SIZE]);
void displayMap(char map[SIZE][SIZE], int x, int y);
void move(int *x, int *y, char direction, char map[SIZE][SIZE]);
void BoxSelect(int x, int y, char map[SIZE][SIZE]);


int main (void)
{
    char map[SIZE][SIZE];
    int consoleRow = 0;
    int *conrowPtr = &consoleRow;
    int consoleCol = 0;
    int *concolPtr = &consoleCol;
    char direction = 0;
    

    initializeMap(map);
    while(1)//loop only stops when game is finished
    {
    printf("Enter + to place your mark\n");
    displayMap(map, consoleRow, consoleCol);
    move(conrowPtr, concolPtr, direction, map);
    BoxSelect(consoleRow, consoleCol, map);
    
    }

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
    }else
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
    /* if(initialdirection == '+')
    {
        BoxSelect(*x, *y, map);
    } */
}
void BoxSelect(int x, int y, char map[SIZE][SIZE])
{
    
    if(map[x][y] == EMPTY)
    {
        map[x][y] = PLAYER;
    } else
    {
        printf("the selected box is already taken.");
    }
}
