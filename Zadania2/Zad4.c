#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char *name;
    float grade;
}Student;

void sortStudents(Student *array, int size);

int main()
{
    srand(time(NULL));
    Student studentArray[100];
    const char *name = "Dawid";

    for (int i = 0; i < 100; i++)
    {
        studentArray[i].name = strdup(name);
        studentArray[i].grade = 2.0 + (rand() % 300) / 100.0; // losowa liczba z zakresu 2 - 5
    }

    int size = sizeof(studentArray) / sizeof(studentArray[0]);

    sortStudents(studentArray, size);

    for (int i = 0; i < size; i++)
    {
        printf("Student name: %s     Student grade: %.2f\n", studentArray[i].name, studentArray[i].grade);
    }
}

void sortStudents(Student *array, int size)
{
    bool swapped;
    for (int i = 0; i < size; i++) 
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (array[j].grade < array[j + 1].grade)
            {
                Student temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}
