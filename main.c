#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_CHAR_LIMIT 50

// reads user's grade percentage for a certain subject

int input_grade_percentage(const char* subject)
{
    int grade_percentage = 0;

    while (1)
    {
        printf("\nEnter your grade for %s (0 - 100): ", subject);

        if (scanf("%d", &grade_percentage) != 1)
        {
            printf("Incorrect input. Please type an integer.\n");
            while(getchar() != '\n');
        }

        else
        {
            if (grade_percentage < 0 || grade_percentage > 100)
            {
                printf("Grade percentage needs to between 0 and 100, try again.\n");
                continue;
            }

            return grade_percentage;
        }
    }
}

// returns grade from 0-5

int grade(int percentage)
{
    if (percentage > )
}

// reads from user the amount of subjects to grade

int input_subject_amount()
{
    int amount = 0;

    while (1)
    {
        printf("\nEnter amount of subjects to grade: ");

        if (scanf("%d", &amount) != 1)
        {
            printf("Incorrect input. Please type an integer.\n");
            while(getchar() != '\n');
        }

        else
        {
            return amount;
        }
    }
}

// reads user's full name

char *input_name()
{
    while (1)
    {
        char name[NAME_CHAR_LIMIT];
        printf("Enter your name (MAX 50 characters): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        int len = strlen(name);

        if (len > NAME_CHAR_LIMIT)
        {
            printf("Name longer than 50 characters, please use initials instead.");
            continue;
        }

        else
        {
            char *name_copy = (char *)malloc((len + 1) * sizeof(char));

            if (name_copy != NULL)
            {
                strcpy(name_copy, name);
                return name_copy;
            }

            else
            {
                printf("Memory allocation failed. Please try again.\n");
                return NULL;
            }
        }
    }
}

int main() {

    char *name = input_name();

    printf("Welcome to the Student Grade Calculator!\n");

    free(name);
    return 0;
}
