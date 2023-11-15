#include <stdio.h>



int main()
{
    int guesses = 0;
    int user_guess;
    int random_number = 7;
    int max_guesses = 5;

    while (guesses <= max_guesses)
    {
        printf("Guess the random number: ");
        scanf("%d", user_guess);

        printf("\n\nYou guessed %d.\n\n", user_guess);

        if (user_guess == random_number)
        {
            printf("\n\nCongratulations you guessed the correct number!\n\n");
            return 0;
        }

        ++guesses;

        printf("That was incorrect, you have %d attempts left.", max_guesses - guesses);
    }

    printf("You have ran out of guesses! Play again!");

    return 0;
}
