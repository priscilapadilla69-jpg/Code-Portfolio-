/**
 * Final Project
 * A program that allows user registration and tracks the available
 * balance in the user's account, including the ability to top it up.
 *
 * Menu options:
 * 1. Personal Information
 * 2. Trip Cost Calculator
 * 3. Available Balance & Top-up
 * 4. Exit
 **/

#include <stdio.h>
#include <math.h>    // Library for mathematical operations
#include <ctype.h>   // Library for isalpha(), used for string validation

// Forward declarations
char registration();
int getAge();
void returnToMenu();


void main()
{
    // Validates that a name contains only letters and spaces
    int validateName(char name[]) {
        int i = 0;
        while (name[i]) {
            if (!isalpha(name[i]) && name[i] != ' ') {  // If char is not a letter or space, fail
                return 0;  // Return false (invalid)
                i++;
            }
            return 1;  // Return true (valid)
        }
    }

    // Validates that a destination contains only letters and spaces
    int validateDestination(char destination[]) {
        int i = 0;
        while (destination[i]) {
            if (!isalpha(destination[i]) && destination[i] != ' ') {  // If char is not a letter or space, fail
                return 0;  // Return false (invalid)
                i++;
            }
            return 1;  // Return true (valid)
        }
    }

    // Prompts the user to enter their name and validates it
    char registration() {
        char name[10];
        printf("Enter your personal information\n ");
        do {
            printf("Enter your name: ");
            scanf("%s", name);
        } while (validateName(name) == 0);  // Keep asking until name is valid
        printf("Name: %s\n", name);
        return name[10];
    }

    // Prompts the user to enter their age and validates it is positive
    int getAge() {
        int age;
        do {
            printf("Enter your age: ");
            scanf("%i", &age);
        } while (age <= 0);  // Keep asking until a positive age is entered
        printf("Age: %i\n", age);
        return age;
    }

    // Variable declarations
    int transport, answer;
    int age, option, update, j;
    char name[10];
    char destination[10];
    float kilometers, tripCost, topUpAmount;
    float cost, balance;

    // Main menu loop — runs until user selects option 4 (Exit)
    while (option != 4) {
        printf("1. Personal Information\n2. Calculate Trip\n3. Balance & Top-up\n4. Exit\n");

        // Keep asking until a valid (positive) option is entered
        do {
            printf("Choose an option: ");
            scanf("%i", &option);
        } while (option <= 0);

        switch (option) {

            case 1:  // Personal Information
                j = 0;

                // First time entering personal info
                while (j == 0) {
                    registration(name);       // Collect name
                    getAge(age);              // Collect age
                    printf("Your information has been saved.\n");
                    j++;
                    break;
                }

                // Subsequent visits: ask if user wants to update info
                while (j > 0) {
                    do {
                        printf("Do you want to update your information? (1.Yes 2.No): ");
                        scanf("%i", &update);
                    } while (update != 1 && update != 2);  // Only accept 1 or 2

                    if (update == 1) {
                        registration(name);   // Re-collect name
                        getAge(age);          // Re-collect age
                        printf("Your information has been updated.\n");
                        break;
                    } else {
                        returnToMenu();       // Go back to main menu
                        break;
                    }
                }
                break;

            case 2:  // Trip Cost Calculator
                do {
                    printf("Do you want to calculate your trip cost? (1.Yes 2.No): ");
                    scanf("%i", &answer);
                } while (answer != 1 && answer != 2);

                if (answer == 1) {
                    // Ask user to choose transport type
                    do {
                        printf("Choose transport: 1.Bus 2.Train");
                        scanf("%i", &transport);
                    } while (transport != 1 && transport != 2);

                    if (transport == 1) {  // Bus destinations
                        do {
                            printf("Quito\nCumbaya\nValle\nSur\nNorte\nEnter your destination: ");
                            scanf("%s", destination);
                            // TODO: convert destination to lowercase for comparison
                        } while (validateDestination(destination) == 0);
                        // TODO: assign a cost value to each stop

                    } else if (transport == 2) {  // Train destinations
                        do {
                            printf("Quito\nTambillo\nMachachi\nBoliche\nEnter your destination: ");
                            scanf("%s", destination);
                        } while (validateDestination(destination) == 0);
                    }
                }
                /* TODO:
                   - Match destination name to a predefined cost value
                   - Apply age-based discounts (children, elderly, etc.)
                   - Deduct trip cost from balance after each trip */
                break;

            case 3:  // Balance & Top-up
                do {
                    printf("Enter the top-up amount: ");
                    scanf("%f", &topUpAmount);
                } while (topUpAmount < 0);  // Reject negative amounts

                balance = balance + topUpAmount;  // Add top-up to current balance
                printf("Your total balance is: %f", balance);
                // TODO: deduct the cost of each trip from balance after travel
                break;

            case 4:  // Exit
                printf("Program ended.");
                break;

            default:  // Invalid input
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

// Displays the main menu and prompts the user to choose an option
void returnToMenu() {
    int option;
    printf("1. Personal Information\n2. Calculate Trip\n3. Balance & Top-up\n");
    do {
        printf("Choose an option: ");
        scanf("%i", &option);
    } while (option <= 0);  // Keep asking until a valid option is entered
}
