#include <iostream>
#include<random>
#include<cstdlib>
#include<ctime>
#include<conio.h>


#include"MapGen.hpp"


int main()
{
    using namespace std;
    srand((unsigned) time(NULL));
    mt19937 gen(rand());


    int dimension = 0, nrOfMines = 0, numOfMines, row, col ,sum;
    char board[25][25] = {' '}, mines[25][25] = {'0'};
    printf(" Hello, and welcome to Minesweeper!\n How big would you like the board to be (Enter a value smaller than 25): ");
    cin >> dimension;
    while (dimension>=25)
    {
        printf(" That number is too big. Enter a smaller value: ");
        cin >> dimension;
    }

    printf(" How many mines would you like to like to spawn (more mines means a more challenging game): ");
    cin >> nrOfMines;
    while (nrOfMines>=dimension*dimension)
    {
        printf(" That number exceeds the dimension of the playing board. Enter a smaller value: ");
        cin >> nrOfMines;
    }

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            board[i][j]='_';
        }
    }

    printf(" Generating map...\n");

    numOfMines = nrOfMines;
    uniform_int_distribution<> distrib(0,dimension-1);
    while (nrOfMines>0)
    {   
        row = distrib(gen);
        col = distrib(gen);
        if (mines[row][col] !='*')
        {
            mines[row][col] = '*';
            nrOfMines--;
        }
        else
        {
            if (row > 0 && col > 0 && mines[row - 1][col - 1] !='*')
            {
                mines[row - 1][col - 1] = '*';
                nrOfMines--;
            }
            else
                if (row > 0 && mines[row - 1][col] !='*')
                {
                    mines[row - 1][col] = '*';
                    nrOfMines--;
                }
                else
                    if (col > 0 && mines[row][col - 1] !='*')
                    {
                        mines[row][col - 1] = '*';
                        nrOfMines--;
                    }
                    else
                        if (row > 0 && col < dimension - 1 && mines[row - 1][col + 1] !='*')
                        {
                            mines[row - 1][col + 1] = '*';
                            nrOfMines--;
                        }
                        else
                            if (row < dimension - 1 && mines[row + 1][col] !='*')
                            {
                                mines[row + 1][col] = '*';
                                nrOfMines--;
                            }
                            else
                                if (row < dimension - 1 && col > 0 && mines[row + 1][col - 1] !='*')
                                {
                                    mines[row + 1][col - 1] = '*';
                                    nrOfMines--;
                                }
                                else
                                    if (row < dimension - 1 && col < dimension - 1 && mines[row + 1][col + 1] !='*')
                                    {
                                        mines[row + 1][col + 1] = '*';
                                        nrOfMines--;
                                    }
                                    else
                                        if (col < dimension - 1 && mines[row][col + 1] !='*')
                                        {
                                            mines[row][col + 1] = '*';
                                            nrOfMines--;
                                        }

        }
    }
    printf(" Map generated\n\n");
    MapGen(dimension, mines);


    bool win = 0, lose = 0;
    while (win == 0 && lose == 0)
    {
        printf(" Rows  Columns ->\n");
        printf(" |\n \\/ \n   ");

        for (int i = 0; i < dimension; i++) printf(" %i", i);
        printf("\n\n");
        
        for (int i = 0; i < dimension; i++)
        {
            printf(" %i ", i);

            for (int j = 0; j < dimension; j++)
            {
                printf(" %c", board[i][j]);
            }

            printf("\n");
        }
        printf("\n Choose element you want to reveal (Exemple: Row: 0  Column: 0)\n");
        printf(" Row: ");
        cin >> row;
        printf(" Column: ");
        cin >> col;

        if (mines[row][col] == '*')
        {
            printf("\n");
            board[row][col] = mines[row][col];

            for (int i = 0; i < dimension; i++)
            {
                for (int j = 0; j < dimension; j++)
                {
                    printf(" %c", mines[i][j]);
                }
                printf("\n");
            }

            lose = 1;
            printf("\n Unfortunately that was a mine, better luck next time! ");
            break;
        }
        else
        {
            board[row][col] = mines[row][col];
        }

        sum = 0;
        for (int i = 0; i < dimension; i++)
        {   
            for (int j = 0; j < dimension; j++)
            {
                if (board[i][j] == '_')
                    sum++;
            }
        }

        if (sum == numOfMines)win = 1;

    }


    if (win == 1) 
    {
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                printf(" %c", mines[i][j]);
            }
            printf("\n");
        }
        printf("\n\n Congratulations, you have conquered Minesweeper, maybe try to make it a little harder. ");
    }

    _getch();
}

