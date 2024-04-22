#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NUMBERS 20
#define MAX_DIGITS 10

int decode(char *line);
int convert_to_int(char *number);
int concat_int(int number1, int number2);


int main() 
{
    int sum = 0;
    FILE *file;
    char line[100];

    file = fopen("input.txt", "r");

    if (file == NULL) 
    {
        printf("Can't read file!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) 
    {
        int energy = decode(line);
        printf("%i\n", energy);
        sum += energy;
    }
    printf("Sum of energy: %i\n", sum);
    fclose(file);

    return 0;
}

int decode(char *line) 
{   
    int count = 0;
    char numbers[MAX_NUMBERS][MAX_DIGITS]; 

    char* wordToFind[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int numWordsToFind = sizeof(wordToFind) / sizeof(wordToFind[0]);

    // Przeszukiwanie ciągu znaków, by znaleźć podciągi lub cyfry
    for (int i = 0; i < strlen(line); i++) 
    {
        if (isdigit(line[i])) 
        {
            char str[MAX_DIGITS]; 
            sprintf(str, "%c", line[i]); 
            strcpy(numbers[count], str); 
            count++;
        }
        else 
        {
            for (int j = 0; j < numWordsToFind; j++) 
            {
                if (strncmp(&line[i], wordToFind[j], strlen(wordToFind[j])) == 0) 
                {
                    strncpy(numbers[count], &line[i], strlen(wordToFind[j])); 
                    numbers[count][strlen(wordToFind[j])] = '\0';
                    count++;
                    i++; 
                    break;
                }
            }
        }
    }
    return concat_int(convert_to_int(numbers[0]), convert_to_int(numbers[count - 1]));
}

int convert_to_int(char *number) // zamiana slownych liczb na int
{
    char* wordToConvert[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int numWords = sizeof(wordToConvert) / sizeof(wordToConvert[0]);
    
    for (int i = 0; i < numWords; ++i) 
    {
        if (strcmp(number, wordToConvert[i]) == 0) 
        {
            return i; 
        }
    }
    
    return atoi(number); 
}

int concat_int(int number1, int number2) // konkatenacja dwoch liczb
{
    char str_number1[20]; 
    char str_number2[20];
    sprintf(str_number1, "%d", number1);
    sprintf(str_number2, "%d", number2);

    strcat(str_number1, str_number2);
    int concatenated_number = atoi(str_number1);

    return concatenated_number;
}