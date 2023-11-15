#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;

    srand((unsigned) time(&t));

    int guesses = 0;
    int user_guess;
    int random_number = rand() % 21;
    int max_guesses = 5;

    while (guesses < max_guesses)
    {
        printf("\nGuess the random number between 0 and 20: ");
        scanf("%d", &user_guess);

        printf("\nYou guessed %d.\n", user_guess);

        if (user_guess == random_number)
        {
            printf("\nCongratulations you guessed the correct number!\n\n");
            return 0;
        }

        if (user_guess < random_number)
        {
            printf("\nYou guessed too low!\n");
        }
        
        if (user_guess > random_number)
        {
            printf("\nYou guessed too high!\n");
        }

        ++guesses;

        printf("\nYou have %d attempts left.\n\n", max_guesses - guesses);
    }

    printf("\nYou have ran out of guesses! Play again!\n\n");

    return 0;
}
