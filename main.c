#include <stdio.h>
#include <string.h>

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
            return grade_percentage;
        }
    }
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


int main() {

    printf("Welcome to the Student Grade Calculator!\n");

    return 0;
}
