#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int rows;
    int col; 
    printf("Enter number of rows: ");
    scanf("%i", &rows);
    printf("\nEnter number of columns: ");
    scanf("%i", &col);

    // tworze dynamiczna alokowana macierz 
    int **pvalues = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) 
    {
        pvalues[i] = (int*)malloc(col * sizeof(int));
    }

    // losuje i przypisuje wartosci
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            pvalues[i][j] = rand() % 10 + 1;
        }
    }

    // wyswietlam wartosci
    for (int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < col; j++) 
        {
            printf("%d ", pvalues[i][j]);
        }
        printf("\n");
    }

    // zwalniam pamiec
    for (int i = 0; i < rows; i++) 
    {
        free(pvalues[i]);
    }

    free(pvalues);
}