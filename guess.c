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

// Function prototypes
void displayMenu(); 
int promptUser();


int main()
{

    int input; 
    bool gameStatus = true; 

    while(gameStatus == true)
    {

        switch(input)


    }



}


void displayMenu()
{
    printf("Press 1 to play a game\n");
    printf("Press 2 tp change the max number\n");
    printf("Press 3 to quit\n");

}