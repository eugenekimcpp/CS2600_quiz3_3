/*
    Program: guess.c

    This is interactive program which gets input from the user to geuss
    a number between 1-10. 

    Menu should look like this: 
        1. Press 1 to play game
            * promt the user to enter a number for guess
            * If correct, tell them they won and back to main menu
            * Else, tell them number is too low or high, and let them guess again
            * This should continue until they win
            * 
            * Input type: number, others are invaild and try again, q is quit
        2. Press 2 to change the max number
            * let the user set the max value (within 1-10)
        3. Press 3 to quit
            * Thank the user and end the game
    

*/
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

// Function prototypes
void displayMenu(); 
int promptUser();
int getGuess(); //promt the user and get the guess input
int checkGuess(int target); // true if correct guess, false otherwise
void suggestGuess(int target); // suggest user if input is too low or high


// Global and Static variables
// Static variable max that saves the user defined max, max is 10
static int max = 10;
int guess = 0;


int main()
{

    //generate RN 1 - 10
    int target, i; 
    time_t t;

    srand((unsigned) time(&t));
    target = (rand()%10) + 1; // it has RN betwen 1 - 10 now. 


    int menuInput; 
    int gameStatus = 1; 

    do {
        // NEW GAME STARTS HERE
        displayMenu();
        menuInput = promptUser();

        // reset the guess at every start of game
        guess = 0; 
        int check = 0; 
        int correctInput;

        switch(menuInput)
        {
            case 1: 
                // actual game implements here
                while (check == 0)
                {
                    // this guess will continue until matching found
                    correctInput = getGuess();
                    if(correctInput == 1)
                    {
                        check = checkGuess(target);
                        if (check == 1)
                        {
                            // if guess is correct
                            prinft("Your guess is correct!!\n");
                        }
                        else{
                            continue;
                        }

                    }
                    else
                    {
                        // when q encounter
                        gameStatus == 1; // game should restart so true
                        check == 1; // game should be over so true
                        break; 
                    }
                }
                // out the loop when have correct guess or restart 

                break;
            case 2:

                break; 

            case 3: 
                printf("Thank you for playing this game! \n");
                gameStatus = 0;
                break; 
            default: 
                printf("Invalid menu input, please pick again...");
                break;
        } // end switch


    } while (gameStatus == 1);



}


void displayMenu()
{
    printf("Press 1 to play a game\n");
    printf("Press 2 tp change the max number\n");
    printf("Press 3 to quit\n");

}

int promptUser()
{
    int choice; 
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    return choice; 

}

int getGuess()
{
    int userInput; 
    printf("Please enter a number to guess: ");
    scanf("%d", &userInput);
    while(1)
    {
        if((userInput > 0) && (userInput < max))
        {
            // when user inputs correct range of guess
            guess = userInput;
            return 1;
        }
        else if(userInput == 113)
        {
            // when user enters 'q'
            return 0;
        }
        // out of rnage + not 'q', then loop again until correct input
    }

}

int checkGuess(int target) 
{
    if (guess == target)
    { 
        return 1; 
    }
    else 
    {
        suggestGuess(target);
        return 0; 
    }
}

void suggestGuess(int target)
{
    if(guess < target) 
    {
        printf("The guess is too low\n");
    }
    else
    {
        printf("The guess is too high\n"); 
    }
}