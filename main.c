#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "core.h"

void menuMain(struct WorkoutDay week[], int max)
{
    int selection;

    printf("WELCOME TO YOUR PERSONAL GYM TRACKER!\n\n");
    do {
        printf("MAIN MENU\n"
               "===================\n"
               "1) View Routine\n"
               "2) Edit Routine\n"
               "3) Add Routine\n"
               "4) Delete Routine\n"
               "-------------------\n"
               "0) Exit System\n"
               "-------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            viewRoutine(week, max);
            break;
        case 2:
            editRoutine(week, max);
            break;
        case 3:
            addRoutine(week, max);
            break;
        case 4:
            deleteRoutine(week, max);
            break;
        }
    } while (selection);
}
void viewRoutine(struct WorkoutDay week[], int max)
{
    int selection;

    do {
        printf("CURRENT ROUTINES\n");
        displayMenu();
        printf("Selection: ");
        selection = inputIntRange(0, 7);
        putchar('\n');
        switch (selection)
        {
        case 1:
            readDay(MONDAY, 0, week, max);
            suspend();
            break;
        case 2:
            readDay(TUESDAY, 1, week, max);
            suspend();
            break;
        case 3:
            readDay(WEDNESDAY, 2, week, max);
            suspend();
            break;
        case 4:
            readDay(THURSDAY, 3, week, max);
            suspend();
            break;
        case 5:
            readDay(FRIDAY, 4, week, max);
            suspend();
            break;
        case 6:
            readDay(SATURDAY, 5, week, max);
            suspend();
            break;
        case 7:
            readDay(SUNDAY, 6, week, max);
            suspend();
            break;
        }
    } while (selection);
}
void editRoutine(struct WorkoutDay week[], int max)
{
    int selection;

    do {
        printf("EDIT ROUTINES\n");
        displayMenu();
        printf("Selection: ");
        selection = inputIntRange(0, 7);
        putchar('\n');
        switch (selection)
        {
        case 1:
            editDay(MONDAY, 0, week, max);
            break;
        case 2:
            editDay(TUESDAY, 1, week, max);
            break;
        case 3:
            editDay(WEDNESDAY, 2, week, max);
            break;
        case 4:
            editDay(THURSDAY, 3, week, max);
            break;
        case 5:
            editDay(FRIDAY, 4, week, max);
            break;
        case 6:
            editDay(SATURDAY, 5, week, max);
            break;
        case 7:
            editDay(SUNDAY, 6, week, max);
            break;
        }
    } while (selection);
}
void addRoutine(struct WorkoutDay week[], int max)
{
    int selection;

    do {
        printf("ADD A NEW ROUTINE\n");
        displayMenu();
        printf("Selection: ");
        selection = inputIntRange(0, 7);
        putchar('\n');
        switch (selection)
        {
        case 1:
            writeDay(MONDAY, 0, week, max);
            break;
        case 2:
            writeDay(TUESDAY, 1, week, max);
            break;
        case 3:
            writeDay(WEDNESDAY, 2, week, max);
            break;
        case 4:
            writeDay(THURSDAY, 3, week, max);
            break;
        case 5:
            writeDay(FRIDAY, 4, week, max);
            break;
        case 6:
            writeDay(SATURDAY, 5, week, max);
            break;
        case 7:
            writeDay(SUNDAY, 6, week, max);
            break;
        }
    } while (selection);
}
void deleteRoutine(struct WorkoutDay week[], int max)
{
    int selection;

    do {
        printf("REMOVE A ROUTINE\n");
        displayMenu();
        printf("Selection: ");
        selection = inputIntRange(0, 7);
        putchar('\n');
        switch (selection)
        {
        case 1:
            deleteDay(MONDAY, 0, week, max);
            break;
        case 2:
            deleteDay(TUESDAY, 1, week, max);
            break;
        case 3:
            deleteDay(WEDNESDAY, 2, week, max);
            break;
        case 4:
            deleteDay(THURSDAY, 3, week, max);
            break;
        case 5:
            deleteDay(FRIDAY, 4, week, max);
            break;
        case 6:
            deleteDay(SATURDAY, 5, week, max);
            break;
        case 7:
            deleteDay(SUNDAY, 6, week, max);
            break;
        }
    } while (selection);
}
int readDay(const char filename[], int day, struct WorkoutDay week[], int max)
{
    int i;
    int isEmpty = 1; // Assume the file is empty
    week[day].numExercises = 0;
    

    FILE* file = fopen(filename, "r");
    if (file == NULL) {            
        printf("Error with file.\n");
    }
    else {                          
        for (i = 0; i < max; i++)
        {
            if (fscanf(file, "%[^0-9] %lf %d %d %[^\n]\n", week[day].exercise[i].name, &week[day].exercise[i].weight, &week[day].exercise[i].sets, &week[day].exercise[i].reps, week[day].exercise[i].notes) == 5)
            {
                week[day].numExercises++;   
                isEmpty = 0; 
            }
        }
        if (!isEmpty)   
        {
            for (i = 0; i < week[day].numExercises; i++)
            {
                printf("Exercise %d: %s\n", i + 1, week[day].exercise[i].name);
                printf("Weight    : %.1lf lbs\n", week[day].exercise[i].weight);
                printf("Sets      : %d\n", week[day].exercise[i].sets);
                printf("Reps      : %d\n", week[day].exercise[i].reps);
                printf("Notes     : %s\n\n", week[day].exercise[i].notes);
            }

        }
        fclose(file);

        if (isEmpty) {
            printf("Log is currently empty.\n\n");
        }
    }
    return isEmpty;
}
void editDay(const char filename[], int day, struct WorkoutDay week[], int max)
{
    int i;
    int isEmpty;
    int selection, selectionTwo;

    isEmpty = readDay(filename, day, week, max);

    if (isEmpty)
    {
        suspend();
    }
    else {
        printf("Which exercise do you want to edit?\n");
        printf("Enter a number: ");
        selection = inputIntRange(1, week[day].numExercises);

        printf("Select the field to edit:\n");
        printf("1) Name\n");
        printf("2) Weight\n");
        printf("3) Sets\n");
        printf("4) Reps\n");
        printf("5) Notes\n");
        printf("------------------\n");
        printf("0) Cancel\n");
        printf("------------------\n");
        printf("Selection: ");
        selectionTwo = inputIntRange(0, 5);

        switch (selectionTwo)
        {
        case 1:
            printf("Enter a new name: ");
            inputCString(week[day].exercise[selection - 1].name, 1, EXERCISE_NAME_LEN);
            break;
        case 2:
            printf("Enter a new weight: ");
            week[day].exercise[selection - 1].weight = inputDoublePositive();
            break;
        case 3:
            printf("Enter a new amount of sets: ");
            week[day].exercise[selection - 1].sets = inputIntPositive();
            break;
        case 4:
            printf("Enter a new amount of reps: ");
            week[day].exercise[selection - 1].reps = inputIntPositive();
            break;
        case 5:
            printf("Enter a new set of notes: ");
            inputCStringNotes(week[day].exercise[selection - 1].notes, 1, WORKOUT_NOTES_LEN);
            break;
        case 0:
            printf("\n");
            printf("Edit aborted.\n");
        }
        if (selectionTwo != 0)
        {
            FILE* file = fopen(filename, "w");
            if (file == NULL) 
            {
                printf("Error with file.\n");
                suspend();
            }
            else 
            {
                for (i = 0; i < max; i++) 
                {
                    if (strcmp(week[day].exercise[i].name, "") != 0)
                    {
                        fprintf(file, "%s %lf %d %d %s\n", week[day].exercise[i].name, week[day].exercise[i].weight, 
                            week[day].exercise[i].sets, week[day].exercise[i].reps, week[day].exercise[i].notes);
                    }
                }
                fclose(file);
                printf("\n");
                printf("Changes saved.\n");    
            }
        }
        suspend();
    }
}
void writeDay(const char filename[], int day, struct WorkoutDay week[], int max)
{
    int i;
    int flag = 0;
    week[day].numExercises = 0;

    //Check if file is valid for adding another exercise
    FILE* file = fopen(filename, "r");
    for (i = 0; i < max; i++)
    {
        if (fscanf(file, "%[^0-9] %lf %d %d %[^\n]\n", week[day].exercise[i].name, &week[day].exercise[i].weight,
            &week[day].exercise[i].sets, &week[day].exercise[i].reps, week[day].exercise[i].notes) == 5)
        {
            week[day].numExercises++;
        }
    }
    fclose(file);

    if (week[day].numExercises >= max)
    {
        printf("More than %d exercises in a session?\n\n", MAX_EXERCISES);
        printf("Avoid overtraining! Let's rearrange your routine.\n");
    }
    else
    {   //Find next available index
        for (i = 0; i < max && flag == 0; i++)
        {
            if (strcmp(week[day].exercise[i].name, "") == 0)
            {
                flag = 1;
            }
        }
        i--; //Next valid index

        printf("Enter exercise name : ");
        inputCString(week[day].exercise[i].name, 1, EXERCISE_NAME_LEN);
        printf("Enter weight        : ");
        week[day].exercise[i].weight = inputDoublePositive();
        printf("Enter sets          : ");
        week[day].exercise[i].sets = inputIntPositive();
        printf("Enter reps          : ");
        week[day].exercise[i].reps = inputIntPositive();
        printf("Enter a set of notes: ");
        inputCStringNotes(week[day].exercise[i].notes, 1, WORKOUT_NOTES_LEN);
        printf("\n");

        FILE* file = fopen(filename, "a");
        if (file == NULL) 
        {
            printf("Error with file.\n");
        }
        else
        {
            if (strcmp(week[day].exercise[i].name, "") != 0)
            {
                fprintf(file, "%s %lf %d %d %s\n", week[day].exercise[i].name, week[day].exercise[i].weight, 
                    week[day].exercise[i].sets, week[day].exercise[i].reps, week[day].exercise[i].notes);
                fclose(file);
                printf("New workout logged.\n");
            }
        }
    }
    suspend();
}
void deleteDay(const char filename[], int day, struct WorkoutDay week[], int max)
{    
    int i;
    int isEmpty;
    int selection;
    char selectionTwo;

    isEmpty = readDay(filename, day, week, max);
    
    if (!isEmpty)
    {
        printf("Which exercise do you want to delete?\n");
        printf("Enter a number: ");
        selection = inputIntRange(1, week[day].numExercises);

        printf("Are you sure you want to delete this exercise routine? (y|n): ");
        selectionTwo = inputCharOption("yn");
        clearInputBuffer();
        if (selectionTwo == 'y')
        {
            FILE* tempFile = fopen("temp.txt", "w");
            if (tempFile == NULL) 
            {
                printf("Error with file.\n");
            }
            else 
            {
                for (i = 0; i < max; i++) 
                {
                    //Write existing data to temporary file except for selected exercise 
                    if (i != selection - 1 && strcmp(week[day].exercise[i].name, "") != 0)
                    {
                        fprintf(tempFile, "%s %lf %d %d %s\n", week[day].exercise[i].name, week[day].exercise[i].weight,
                            week[day].exercise[i].sets, week[day].exercise[i].reps, week[day].exercise[i].notes);
                    }
                }
                fclose(tempFile);

                if (remove(filename) == 0) //Delete original file
                {
                    if (rename("temp.txt", filename) == 0) //Rename temporary file
                    {
                        //Sort the indexes accordingly
                        for (i = selection - 1; i < MAX_EXERCISES - 1; i++)
                        {
                            week[day].exercise[i] = week[day].exercise[i + 1];
                        }
                    //Clear the last element so it won't be written to any file
                    strcpy(week[day].exercise[MAX_EXERCISES - 1].name, "\0");
                    week[day].exercise[MAX_EXERCISES - 1].weight = 0;
                    week[day].exercise[MAX_EXERCISES - 1].sets = 0;
                    week[day].exercise[MAX_EXERCISES - 1].reps = 0;
                    strcpy(week[day].exercise[MAX_EXERCISES - 1].notes, "\0");

                    printf("\n");
                    printf("Successfully removed.\n");
                    }
                    else
                    {
                        printf("Error! Try again.");
                    }
                }
            }
        }
        else 
        {
            printf("\n");
            printf("Removal aborted.\n");
        }
    }
    suspend();
}
void displayMenu()
{
    printf("===================\n");
    printf("1) Monday\n");
    printf("-------------------\n");
    printf("2) Tuesday\n");
    printf("-------------------\n");
    printf("3) Wednesday\n");
    printf("-------------------\n");
    printf("4) Thursday\n");
    printf("-------------------\n");
    printf("5) Friday\n");
    printf("-------------------\n");
    printf("6) Saturday\n");
    printf("-------------------\n");
    printf("7) Sunday\n");
    printf("-------------------\n");
    printf("0) Previous menu\n");
    printf("-------------------\n");
}