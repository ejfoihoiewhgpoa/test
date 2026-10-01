#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lower, upper, target, guess;
    int count = 0, flag = 0;
    int total_chances;

    // Take lower bound input
    printf("Enter Lower Bound: ");
    scanf("%d", &lower);

    // Take upper bound input
    printf("Enter Upper Bound: ");
    scanf("%d", &upper);

    // Validate range
    if (lower >= upper) {
        printf("Error: Upper bound must be greater than lower bound.\n");
        return 0;
    }

    // Seed the random number generator
    srand(time(0));

    // Generate a random number within the range
    target = (rand() % (upper - lower + 1)) + lower;

    // Calculate maximum chances using binary search principle
    total_chances = (int)ceil(log(upper - lower + 1) / log(2));

    // Ensure at least one chance
    if (total_chances < 1) {
        total_chances = 1;
    }

    printf("\nYou have only %d chances to guess the number!\n\n",
           total_chances);

    // Guessing loop
    while (count < total_chances) {
        count++;

        printf("Guess a number: ");
        scanf("%d", &guess);

        if (guess == target) {
            printf("\nCongratulations! You guessed the number in %d attempt(s).\n",
                   count);
            flag = 1;
            break;
        }
        else if (guess < target) {
            printf("You guessed too low!\n");
        }
        else {
            printf("You guessed too high!\n");
        }
    }

    // If user fails to guess the number
    if (!flag) {
        printf("\nThe correct number was %d.\n", target);
        printf("Better luck next time!\n");
    }

    return 0;
}