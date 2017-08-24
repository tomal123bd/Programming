#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <windows.h>
void search_pos (char board[3][3] , char plr_pos , char xy);
int exist_pos (char board[3][3] , char plr_pos);
int game_over (char board[3][3]);
int valid_pos (char pos);
void print_pos (char board[3][3]);
int random_num();
int main ()
{
    char board[3][3],count=49,plr_x,plr_o,c; /* char c is for \n */
    int i,j,pos;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
           board[i][j]=count;
           count++;
        }
    }
    print_pos(board);
    for (i=0;i<9;i++)
    {
        if (i%2==0)
        {
            if (game_over(board)==1)
            {
                printf ("\no Winner\n");
                break;
            }
            do {
                //printf ("Input Position for x : \n");
                //scanf ("%d",&pos);
                printf ("Please wait..........\n");
                srand(time(0));
                pos=random_num();
                if (pos>=1 && pos<=9)
                {
                    plr_x=48+pos; /* converting int to char positon */
                    if (exist_pos(board,plr_x)!=0)
                    {
                        //printf ("\nPosition already exist, please try again\n");
                        printf ("Please wait..........\n");
                    }
                }
                else
                {
                    //printf ("\nInvalid Position ! Please try again.\n");
                    printf ("Please wait..........\n");
                }
            } while (exist_pos(board,plr_x)!=0 || (pos<1 || pos>9));
            search_pos (board,plr_x,'x');
            print_pos (board);
        }
        else
        {
            if (game_over(board)==1)
            {
                printf ("\nx Winner\n");
                break;
            }
            do {
                printf ("Input Position for o : ");
                scanf ("%d",&pos);
                if (pos>=1 && pos<=9)
                {
                    plr_o=48+pos; /* converting int to char positon */
                    if (exist_pos(board,plr_o)!=0)
                    {
                        printf ("\nPosition already exist, please try again\n");
                    }
                }
                else
                {
                    printf ("\nInvalid Position ! Please try again.\n");
                }
            } while (exist_pos(board,plr_o)!=0 || (pos<1 || pos>9));
            search_pos (board,plr_o,'o');
            print_pos (board);
        }
    }
    if (game_over(board)!=1)
    {
        printf ("\nDraw\n");
    }
    else if (i==9 && game_over(board)==1)
    {
        printf ("\nx winner\n");
    }
    //getch();
    return 0;
}

void search_pos (char board[3][3] , char plr_pos , char xy) /* function to search position and to keep 'x' or 'o' in the selected index */
{
    system("clear");
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (board[i][j]==plr_pos)
            {
                board[i][j]=xy;
                break;
            }
        }
    }
}

int exist_pos (char board[3][3] , char plr_pos) /* function to check if selected position already exist or not */
{
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            if (board[i][j]==plr_pos)
            {
                return 0;
            }
        }
    }
    return 1;
}

int game_over (char board[3][3]) /* function to check that game over or not */
{
    int i,j,x=0,y=0;
    int squire_chk=1,plus_chk=1,cross_chk=1;
    char chk;
    chk=board[0][0];
    for (i=0;i<3;i++) /* squire check */
    {
        if (chk==board[0][i])
        {
            chk=board[0][i];
            continue;
        }
        else
        {
            break;
        }
    }
    if (i==3)
    {
        return 1;
    }
    /*---*/
    chk=board[0][2];
    for (i=2;i>=0;i--)
    {
        if (chk==board[i][2])
        {
            chk=board[i][2];
            continue;
        }
        else
        {
            break;
        }
    }
    if (i==-1)
    {
        return 1;
    }
    /*---*/
    chk=board[2][0];
    for (i=0;i<3;i++)
    {
        if (chk==board[2][i])
        {
            chk=board[2][i];
            continue;
        }
        else
        {
            break;
        }
    }
    if (i==3)
    {
        return 1;
    }
    /*---*/
    chk=board[0][0];
    for (i=0;i<3;i++)
    {
        if (chk==board[i][0])
        {
            chk=board[i][0];
            continue;
        }
        else
        {
            break;
        }
    }
    if (i==3)
    {
        return 1;
    }
    /*---*/
    chk=board[0][0]; /* cross check 1 */
    for (i=0;i<3;i++)
    {
        if (chk==board[i][i])
        {
            chk=board[i][i];
            continue;
        }
        else
        {
            break;
        }
    }
    if (i==3)
    {
        return 1;
    }
    /*---*/
    chk=board[2][0]; /* cross check 2 */
    for (i=2,j=0;i>=0;i--,j++)
    {
        if (chk==board[i][j])
        {
            chk=board[i][j];
            continue;
        }
        else
        {
            break;
        }
    }
    if (i==-1)
    {
        return 1;
    }
    /*---*/
    chk=board[0][1]; /* plus check 1 */
    for (i=0;i<3;i++)
    {
        if (chk==board[i][1])
        {
            chk=board[i][1];
            continue;
        }
        else
        {
            break;
        }
    }
    if (i==3)
    {
        return 1;
    }
    /*---*/
    chk=board[1][0]; /* plus check 2 */
    for (i=0;i<3;i++)
    {
        if (chk==board[1][i])
        {
            chk=board[1][i];
            continue;
        }
        else
        {
            break;
        }
    }
    if (i==3)
    {
        return 1;
    }
}

void print_pos (char board[3][3]) /*function for printing positon */
{
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<2;j++)
        {
           printf ("  %c  |",board[i][j]);
        }
        printf ("  %c  ",board[i][j]);
        printf ("\n\n");
    }
}

int random_num()
{
    return 1+rand()%9;
}
