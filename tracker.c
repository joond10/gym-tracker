#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "main.h"

int main(void)
{
    // Initialize an array of WorkoutDay for a week
    struct WorkoutDay week[MAX_DAYS] = { { 0 } };

    // Call the main menu function 
    menuMain(week, MAX_EXERCISES);

    return 0;
}
