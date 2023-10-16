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


int main() {

    printf("Welcome to the Student Grade Calculator!\n");

    return 0;
}
