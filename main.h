//////////////////////////////////////
// MACROS
//////////////////////////////////////

#define MAX_DAYS 7
#define MAX_EXERCISES 15
#define EXERCISE_NAME_LEN 50
#define WORKOUT_NOTES_LEN 100
#define MONDAY      "monday.txt"
#define TUESDAY     "tuesday.txt"
#define WEDNESDAY   "wednesday.txt"
#define THURSDAY    "thursday.txt"
#define FRIDAY      "friday.txt"
#define SATURDAY    "saturday.txt"
#define SUNDAY      "sunday.txt"

//////////////////////////////////////
// Structures
//////////////////////////////////////

// Struct to represent an exercise
struct Workout 
{
    char name[EXERCISE_NAME_LEN];  
    double weight;   
    int sets;       
    int reps;       
    char notes[WORKOUT_NOTES_LEN]; 
};
// Struct to represent a day's workout routine
struct WorkoutDay
{
    struct Workout exercise[MAX_EXERCISES];
    int numExercises;
};

//////////////////////////////////////
// Menu Functions
//////////////////////////////////////

void menuMain(struct WorkoutDay week[], int max);

void viewRoutine(struct WorkoutDay week[], int max);

void editRoutine(struct WorkoutDay week[], int max);

void addRoutine(struct WorkoutDay week[], int max);

void deleteRoutine(struct WorkoutDay week[], int max);

//////////////////////////////////////
// File Handling Functions
//////////////////////////////////////

int readDay(const char filename[], int day, struct WorkoutDay week[], int max);

void editDay(const char filename[], int day, struct WorkoutDay week[], int max);

void writeDay(const char filename[], int day, struct WorkoutDay week[], int max);

void deleteDay(const char filename[], int day, struct WorkoutDay week[], int max);

//////////////////////////////////////
// Display Functions
//////////////////////////////////////

void displayMenu();