#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_num()
{
    return 1+rand()%6;
}

int game_func(int player,int pick,int snake_catch[],int snake_down[],int ladder_catch[],int ladder_up[])
{
    int i,snake=8,ladder=6;;
    printf ("\t\t\t>>> Player picked: %d\n",pick);
    if (pick==1 && player<99){
        pick=random_num();
        printf ("\t\t\t>>> Player picked 2nd time: %d\n",pick);
        if (pick==1){
            pick=random_num();
            printf ("\t\t\t>>> Player picked 3rd time: %d\n",pick);
            if (pick==1){
                printf ("\t\t\t>>> Player picked: %d (Move denied)\n",pick);
                return player;
            }
        }
    }
    if (player+pick>100){
        printf ("\t\t\t>>> Player Position %d (Move denied for overflow)\n",player);
        return player;
    }
    player=player+pick;
    printf ("\t\t\t>>> Player Position %d\n",player);
    for (i=0;i<snake;i++){
        if (snake_catch[i]==player){
            printf ("\t\t\tSnake Catches in %d (Move down to %d)\n",snake_catch[i],snake_down[i]);
            player=snake_down[i];
            return player;
        }
    }
    for (i=0;i<ladder;i++){
        if (ladder_catch[i]==player){
            printf ("\t\t\tLadder Catches in %d (Move up to %d)\n",ladder_catch[i],ladder_up[i]);
            player=ladder_up[i];
            return player;
        }
    }
    return player;
}

int main ()
{
    int i;
    int player1=1,computer=1,start,flag1=0,flag2=0,flag3=0,pick;
    int snake_catch[]={32,60,63,70,73,82,89,97};
    int snake_down[]={13,38,3,12,47,43,53,12};
    int ladder_catch[]={6,8,26,50,55,59};
    int ladder_up[]={16,41,29,94,80,84};
    while (1){
        printf ("Input 1:");
        scanf ("%d",&start);
        system("clear");
        srand(time(0));
        if (random_num()==1 && flag1==0) {flag1=1;printf ("Player 1 have released %d\n",player1);}
        if (random_num()==1 && flag2==0) {flag2=1;printf ("Computer have released %d\n",computer);}
        if (flag1==1){
            printf ("\n\t\t\t\t---Player 1---\n\n");
            pick=random_num();
            player1=game_func(player1,pick,snake_catch,snake_down,ladder_catch,ladder_up);
            printf ("* Player 1 Position %d\n",player1);
            for (i=0;i<8;i++){
                if (player1<snake_catch[i]){
                    printf ("\tNext Snake @ %d\n",snake_catch[i]);
                    break;
                }
            }
            for (i=0;i<8;i++){
                if (player1<ladder_catch[i]){
                    printf ("\tNext Ladder @ %d\n",ladder_catch[i]);
                    break;
                }
            }
        }
        if (flag2==1){
            printf ("\n\t\t\t\t---Computer---\n\n");
            pick=random_num();
            computer=game_func(computer,pick,snake_catch,snake_down,ladder_catch,ladder_up);
            printf ("\t\t\t\t\t\t\t* Computer Position %d\n",computer);
            for (i=0;i<8;i++){
                if (computer<snake_catch[i]){
                    printf ("\t\t\t\t\t\t\tNext Snake @ %d\n",snake_catch[i]);
                    break;
                }
            }
            for (i=0;i<8;i++){
                if (computer<ladder_catch[i]){
                    printf ("\t\t\t\t\t\t\tNext Ladder @ %d\n",ladder_catch[i]);
                    break;
                }
            }
        }
        if (player1==100 || computer==100)break;
    }
    if (computer>player1) printf ("Computer win\n");
    else printf ("Player 1 win\n");
    return 0;
}
