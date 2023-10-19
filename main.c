#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SUBJECT_CHAR_LIMIT 50

// reads user's grade percentage for a certain subject

int input_grade_percentage(const char* subject)
{
    int grade_percentage = 0;

    while (1)
    {
        printf("\nEnter your score for %s (0 - 100): ", subject);

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

// determining grade from percentage

int grade(int percentage)
{
    int grade = 0;

    if (percentage >= 90)
    {
        grade = 5;
    }
    else if (percentage >= 80)
    {
        grade = 4;
    }
    else if (percentage >= 70)
    {
        grade = 3;
    }
    else if (percentage >= 60)
    {
        grade = 2;
    }
    else if (percentage >= 50)
    {
        grade = 1;
    }
    else
    {
        grade = 0;
    }

    return grade;
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
        char name[NAME_SUBJECT_CHAR_LIMIT];
        printf("\nEnter your name (MAX 50 characters): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        int len = strlen(name);

        if (len > NAME_SUBJECT_CHAR_LIMIT)
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

// reads user's subject

char *input_subject(int subject_number)
{
    while (1)
    {
        char subject[NAME_SUBJECT_CHAR_LIMIT];

        // clearing the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("\nEnter subject %d name (MAX 50 characters): ", subject_number);
        fgets(subject, sizeof(subject), stdin);
        subject[strcspn(subject, "\n")] = '\0';

        int len = strlen(subject);

        if (len > NAME_SUBJECT_CHAR_LIMIT)
        {
            printf("Subject name is longer than 50 characters, shorten it.");
            continue;
        }

        else
        {
            char *subject_copy = (char *)malloc((len + 1) * sizeof(char));

            if (subject_copy != NULL)
            {
                strcpy(subject_copy, subject);
                return subject_copy;
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

    printf("Welcome to the Student Grade Calculator!\n");

    FILE *file = fopen("student_report.txt", "w"); // txt file located in cmake-build-debug directory

    if (file == NULL)
    {
        printf("Error opening the file for writing. Try changing the file name.\n");
        return 1;
    }

    char *name = input_name();

    int subject_amount = input_subject_amount();

    int total = 0;

    // making arrays of subjects, their percentages and grades
    char **subjects= (char **) malloc(subject_amount * sizeof(char *)); // allocate memory for an array of strings
    int subjects_percentage[subject_amount];
    int subjects_grade[subject_amount];

    for (int i = 0; i < subject_amount; i++)
    {
        subjects[i] = input_subject(i + 1);
        subjects_percentage[i] = input_grade_percentage(subjects[i]);
        subjects_grade[i] = grade(subjects_percentage[i]);
        total += subjects_grade[i];
    }

    float avg = (float)total/(float)subject_amount; // calculates gpa, num. and denom. converted to float

    printf("\n-----------------------------------------------");
    printf("\nStudent: %s\n", name);
    printf("-----------------------------------------------");
    printf("\n%-30sScore\tGrade\n", "Subjects");
    printf("-----------------------------------------------\n");

    for (int j = 0; j < subject_amount; j++)
    {
        printf("%-32s%d%%\t%5d\n", subjects[j], subjects_percentage[j], subjects_grade[j]);
    }

    printf("-----------------------------------------------\n");
    printf("Average Grade: %.2f\n", avg);
    printf("-----------------------------------------------\n");

    // printing the report to the file
    fprintf(file, "-----------------------------------------------\n");
    fprintf(file, "Student: %s\n", name);
    fprintf(file, "-----------------------------------------------\n");
    fprintf(file, "%-30sScore\tGrade\n", "Subjects");
    fprintf(file, "-----------------------------------------------\n");

    for (int j = 0; j < subject_amount; j++) {
        fprintf(file, "%-32s%d%%\t%5d\n", subjects[j], subjects_percentage[j], subjects_grade[j]);
    }

    fprintf(file, "-----------------------------------------------\n");
    fprintf(file, "Average Grade: %.2f\n", avg);
    fprintf(file, "-----------------------------------------------\n");

    fclose(file);

    free(name);

    for (int i = 0; i < subject_amount; i++)
    {
        free(subjects[i]); // freeing memory for each element of array
    }

    free(subjects); // freeing memory for whole array
    return 0;
}
