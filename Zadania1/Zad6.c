#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    int scores[5][3] = {0}; //wyniki rund
    char playerHistory[5][10], opponentHistory[5][10]; //historia zagranych ruchow gracza i przeciwnika

    for (int round = 0; round < 5; round++) // 5 rund
    {
        char action[10];
        char *opponentAction;
        int playerResult, opponentResult;
        // petla do while by uzytkownik podal jedna z mozliwych opcji
        do
        {
            printf("Enter your move ('Rock', 'Paper', 'Scissors')\n");
            printf("Enter 'scores' to see results\n");
            printf("Enter '0' to exit\n");
            printf("Enter: ");
            scanf("%s", action);
            
            if (strcmp(action, "0") == 0)
            {
                return 0;
            }
            // wyswietla historie rund
            else if (strcmp(action, "scores") == 0)
            {
                printf("\nScores:\n");
                for (int i = 0; i < round; i++)
                {
                    printf("Round %d: Player: %s - Opponent: %s -- ", i + 1, playerHistory[i], opponentHistory[i]);
                    if (scores[i][0] == scores[i][1])
                        printf("Draw\n");
                    else if ((scores[i][0] == 1 && scores[i][1] == 2))
                        printf("Player wins\n");
                    else
                        printf("Opponent wins\n");
                    printf("\n");
                }
                continue;
            }
            printf("\n");
        } while (strcmp(action, "Rock") != 0 && strcmp(action, "Paper") != 0 && strcmp(action, "Scissors") != 0);

        int n = rand() % 3 + 1; // losowanie liczby od 1 do 3 i przypisanie ruchu przeciwnika 
        switch (n)
        {
        case 1:
            opponentAction = "Rock";
            break;
        case 2:
            opponentAction = "Paper";
            break;
        case 3:
            opponentAction = "Scissors";
            break;
        default:
            break;
        }
        printf("Opponent action: %s\n", opponentAction);

        // sprawdza kto wygral
        if (strcmp(action, opponentAction) == 0)
        {
            printf("It's a draw!\n");
            playerResult = opponentResult = 0;
        }
        else if ((strcmp(action, "Rock") == 0 && strcmp(opponentAction, "Scissors") == 0) ||
                 (strcmp(action, "Paper") == 0 && strcmp(opponentAction, "Rock") == 0) ||
                 (strcmp(action, "Scissors") == 0 && strcmp(opponentAction, "Paper") == 0))
        {
            printf("You win!\n");
            playerResult = 1;
            opponentResult = 2;
        }
        else
        {
            printf("Opponent wins!\n");
            playerResult = 2;
            opponentResult = 1;
        }

        scores[round][0] = playerResult;
        scores[round][1] = opponentResult;
        
        // zapisuje ruchy gracza i przeciwnika do historii
        if (strcmp(action, "Rock") == 0)
        {
            strcpy(playerHistory[round], "Rock");
        }
        else if (strcmp(action, "Paper") == 0)
        {
            strcpy(playerHistory[round], "Paper");
        }
        else
        {
            strcpy(playerHistory[round], "Scissors");
        }

        if (strcmp(opponentAction, "Rock") == 0)
        {
            strcpy(opponentHistory[round], "Rock");
        }
        else if (strcmp(opponentAction, "Paper") == 0)
        {
            strcpy(opponentHistory[round], "Paper");
        }
        else
        {
            strcpy(opponentHistory[round], "Scissors");
        }
        printf("\n");
    }
    // wyswietla na koniec historie rund
    printf("Game Over. Final Scores:\n");
    for (int i = 0; i < 5; i++)
        {
            printf("Round %d: Player: %s - Opponent: %s -- ", i + 1, playerHistory[i], opponentHistory[i]);
            if (scores[i][0] == scores[i][1])
                printf("Draw\n");
            else if ((scores[i][0] == 1 && scores[i][1] == 2))
                printf("Player wins\n");
            else
                printf("Opponent wins\n");
            printf("\n");
        }

    return 0;
}