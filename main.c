// C program that calculates either you age or birth year
// depending on what information you pass it

#include <stdio.h>
#include <time.h>

// Declaration of date
struct date {
    int day;
    int month;
    int year;
};

// Function to calculate birth year based on age
int calculateBirthYear(int currentYear, int age) {
    return currentYear - age;
}

int main() {
    // Declare a variable of type struct date
    struct date dt;

    //Get current system time
    time_t t;
    struct tm* current_time;

    time(&t);
    current_time = localtime(&t);

    // Assign values to struct date members
    dt.day = current_time->tm_mday;
    dt.month = current_time->tm_mon + 1; // Month is 0-indexed
    dt.year = current_time->tm_year + 1900; // Years since 1900

    // print the current date
    printf("System current date\n");
    printf("%d/%d/%d\n", dt.day, dt.month, dt.year);

    // Get user input for age
    int age;
    printf("Enter your age or birth year: ");
    scanf("%d", &age);

    // Calculate birth year
    int birthYear =  calculateBirthYear(dt.year, age);

    // Print the calculated birth year
    printf("Your birth year or age is: %d\n", birthYear);

    return 0;
}
