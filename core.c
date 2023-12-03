#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue 
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// Get a valid integer from the keyboard 
int inputInt(void)
{
    int value, done = 0;
    char newline = 'x';

    do {
        scanf("%d%c", &value, &newline);
        if (newline == '\n') {
            done = 1;
        }
        else {
            clearInputBuffer();
            printf("ERROR! Input a whole number: ");
        }
    } while (!done);

    return value;
}

// Get a valid double from the keyboard
double inputDouble(void)
{
    int done = 0;
    double value = 0.0;
    char newline = 'x';

    do {
        scanf("%lf%c", &value, &newline);
        if (newline == '\n') {
            done = 1;
        }
        else {
            clearInputBuffer();
            printf("ERROR! Input a whole number: ");
        }
    } while (!done);

    return value;
}

//Validates if inputInt is greater than zero
int inputIntPositive(void)
{
    int value = 0;

    do {

        value = inputInt();
        if (!(value >= 0))
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (!(value >= 0));

    return value;
}

//Validates if inputDouble is greater than zero
double inputDoublePositive(void)
{
    double value = 0.0;

    do {

        value = inputDouble();
        if (!(value >= 0.0))
        {
            printf("ERROR! Value must be > 0.0: ");
        }
    } while (!(value >= 0.0));

    return value;
}

//Validates the value entered is between the two arguments 
int inputIntRange(int lowerBound, int upperBound)
{
    int value = 0;

    do {
        value = inputInt();
        if (!(value >= lowerBound && value <= upperBound))
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (!(value >= lowerBound && value <= upperBound));

    return value;
}

// Get a single character value and validate for a match of 
// any of the characters in the received C string argument
char inputCharOption(const char str[])
{
    char validChar[10] = { '\0' };
    int valid = 0;
    int i, len;

    do {
        scanf(" %s", validChar);
        len = strlen(validChar);

        for (i = 0; str[i] != '\0' && valid == 0; i++)
        {
            if (len == 1 && validChar[0] == str[i])
            {
                valid = 1;
            }
        }
        if (!valid)
        {
            printf("ERROR! Character must be one of [%s]: ", str);
        }

    } while (!valid);

    return validChar[0];
}

// Obtain user input for a C string value with a length 
// in the character range specified by the 2nd and 3rd arguments received(inclusive)
void inputCString(char str[], int minLen, int maxLen)
{
    char temp[500] = { '\0' };
    int isValid = 1;
    int i;

    do {
        scanf("%[^\n]", temp);
        clearInputBuffer();

        if (strlen(temp) > maxLen)
        {
            printf("ERROR! Notes cannot exceed more than %d characters: ", maxLen);
        }
        else if (strlen(temp) < minLen)
        {
            printf("ERROR! Notes must be between %d and %d characters: ", minLen, maxLen);
        }
        else
        {
            isValid = 1;
            for (i = 0; temp[i] != '\0'; i++)
            {
                if (isdigit(temp[i]))
                {
                    isValid = 0;
                }
            }
            if (!isValid)
            {
                printf("ERROR! Please enter a string with non-numeric characters: ");
            }
        }
    } while (!isValid);

    for (i = 0; i < maxLen; i++) 
    {
        str[i] = temp[i];
    }
}

// Obtain user input for a C string value with a length 
// in the character range specified by the 2nd and 3rd arguments received(inclusive)
// Inclusive of numeric characters
void inputCStringNotes(char str[], int minLen, int maxLen)
{
    char temp[500] = { '\0' };
    int isValid = 1;
    int i;

    do {
        scanf("%[^\n]", temp);
        clearInputBuffer();

        if (strlen(temp) > maxLen)
        {
            printf("ERROR! Notes cannot exceed more than %d characters: ", maxLen);
        }
        else if (strlen(temp) < minLen)
        {
            printf("ERROR! Notes must be between %d and %d characters: ", minLen, maxLen);
        }
    } while (strlen(temp) < minLen || strlen(temp) > maxLen);

    for (i = 0; i < maxLen; i++)
    {
        str[i] = temp[i];
    }
}