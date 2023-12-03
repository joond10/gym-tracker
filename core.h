// SAFE-GUARD: 
#ifndef CORE_H
#define CORE_H

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get a valid integer from the keyboard
int inputInt(void);

// Get a valid double from the keyboard
double inputDouble(void);

// Validates if input is greater than zero
int inputIntPositive(void);

// Validates if input is greater than zero
double inputDoublePositive(void);

// Validates the value entered is between the two arguments 
int inputIntRange(int lowerBound, int upperBound);

// Get a single character value and validate for a match of 
// any of the characters in the received C string argument
char inputCharOption(const char str[]);

// Obtain user input for a C string value with a length 
// in the character range specified by the 2nd and 3rd arguments received(inclusive)
void inputCString(char str[], int minLen, int maxLen);

// Obtain user input for a C string value with a length 
// in the character range specified by the 2nd and 3rd arguments received(inclusive)
// Inclusive of numeric characters
void inputCStringNotes(char str[], int minLen, int maxLen);

#endif // !CORE_H