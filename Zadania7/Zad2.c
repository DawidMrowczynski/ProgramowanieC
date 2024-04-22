#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct  
{
    bool poss;
    int power;
} Result;

Result is_possible(char *line, int b, int g, int r, int n);

int main()
{
    // maksymalne liczby danych kolorow dla problemu 1
    int b_number = 14;
    int g_number = 13;
    int r_number = 12;

    int sum_power = 0;
    int possible = 0; // do sumy identyfikatorow
    int counter = 1; // numer gry: zaczynamy od 1 gry

    FILE *file;
    char line[200];

    file = fopen("input2.txt", "r");

    if (file == NULL) 
    {
        printf("Can't read file!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) 
    {
        Result answer = is_possible(line, b_number, g_number, r_number, counter);
        if (answer.poss)
        {
            possible += counter;
        }
        printf("Game %i: %s\n", counter, answer.poss ? "Possible" : "Not Possible");
        counter++;
        sum_power += answer.power;
    }
    printf("Sum of Identifiers: %i\n", possible);
    printf("Sum of Power: %i\n", sum_power);

    fclose(file);

    return 0;
}

Result is_possible(char *line, int b, int g, int r, int n)
{
    Result answers;
    answers.poss = true;
    int max_blue = 0;
    int max_green = 0;
    int max_red = 0;
    int count = 0, count_max = 0;
    char *splited, *splited_inner;

    // sprawdzam ile cyfr ma numer gry aby go odpowienio odciac (numer gry - np. Game 100:) 
    char buffer[20];
    sprintf(buffer, "%d", n);
    int len = strlen(buffer);
    char *new_line = line + 7 + len;

    splited = strtok(new_line, ";"); // dziele string po sredniku
    char *results[20], *inner_results[50];

    while (splited != NULL)
    {
        results[count] = splited;
        splited = strtok(NULL, ";");
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        splited_inner = strtok(results[i], ", "); // dziele dalej ale po przecinku

        while (splited_inner != NULL)
        {
            inner_results[count_max] = splited_inner;
            splited_inner = strtok(NULL, ", ");
            count_max++;
        }
    }
    for (int i = 0; i < count_max; i += 2) // wyszukuje maksymalne wartosci
    {
        if (i + 1 < count_max)
        {
            if ((strcmp(inner_results[i + 1], "blue") == 0 || strcmp(inner_results[i + 1], "blue\n") == 0) && atoi(inner_results[i]) > max_blue)
            {
                max_blue = atoi(inner_results[i]);
            }
            if ((strcmp(inner_results[i + 1], "green") == 0 || strcmp(inner_results[i + 1], "green\n") == 0) && atoi(inner_results[i]) > max_green)
            {
                max_green = atoi(inner_results[i]);
            }
            if ((strcmp(inner_results[i + 1], "red") == 0 || strcmp(inner_results[i + 1], "red\n") == 0) && atoi(inner_results[i]) > max_red)
            {
                max_red = atoi(inner_results[i]);
            }
        }
    }
    if (b < max_blue) // warunki do sprawdzenia pierwszej czesci zadania
    {
        answers.poss = false;
    }
    if (g < max_green)
    {
        answers.poss = false;
    }
    if (r < max_red)
    {
        answers.poss = false;
    }

    answers.power = max_blue * max_green * max_red;
    return answers;
}