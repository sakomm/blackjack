#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genCard();
int deal();

typedef struct
{
    int playerSum;
    int playerBalence;
    int bet;
} player;

player Player, Dealer;

__time_t t;

int deck[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
int val[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int genCard()
{
    srand((unsigned)time(&t));

    int randVal = rand() % 13;

    while (val[randVal] > 4)
    {
        randVal = rand() % 13;
    }

    return deck[randVal];
}

int playgame()
{
    Player.playerSum = 0;
    Dealer.playerSum = 0;

    printf("\nPlace Bet -->\n");

    int betAmount;

    scanf("%d", &betAmount);
    while (betAmount > Player.playerBalence)
    {
        printf("INVALID BET AMOUNT TRY AGAIN\n");
        scanf("%d", &betAmount);
    }

    Player.bet = betAmount;

    printf("Begining Round\n");

    //pregame dealing has been handled 

    Player.playerSum = Player.playerSum + genCard() + genCard();
    printf("You have as your total --> %d\n", Player.playerSum);
    Dealer.playerSum = Dealer.playerSum + genCard();
    printf("Dealer has at least --> %d\n", Dealer.playerSum);
    Dealer.playerSum = Dealer.playerSum + genCard();

    int input;
    do
    {
        /* code */
        printf("Game Menu\n=======================\n");
        printf("1 --> HIT\n");
        printf("2 --> STAND\n");

        scanf("%d", &input);

        switch (input)
        {
        case 1:
            Player.playerSum = genCard();

            if(Player.playerSum > 21){
                printf("P")
            }
            break;

        case 2:
            input = 2;   
            break;

        default:
            printf("INVALID INPUT DETECTED \nRE-ENTER VALID INPUT TO PROCEED\n");
        }

    } while (input != 2);
    

    return 0;
}

int main()
{
    printf(" ___   ___\n|A  | |10 |\n| ♣ | | ♦ |\n|__A| |_10|\n");
    int input;

    do
    {
        /* code */
        printf("Player Menu\n=======================\n");
        printf("1 --> Set user start amount\n");
        printf("2 --> Begin game\n");
        printf("3 --> Quit\n");

        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("Set intial Balence: \t");
            scanf("%d", &Player.playerBalence);
            printf("\n=======================\n");
            printf("Player Balence is: --> $%d", Player.playerBalence);
            printf("\n=======================\n");
            /* code */
            break;

        case 2:
            playgame();
            break;

        case 3:
            input = 3;
            break;

        default:
            printf("INVALID INPUT DETECTED \nRE-ENTER VALID INPUT TO PROCEED\n");
        }

    } while (input != 3);

    printf(" ___   ___\n|A  | |10 |\n| ♣ | | ♦ |\n|__A| |_10|");
    printf("THANK YOU FOR PLAYING");
    return 0;
}
