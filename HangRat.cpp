// HangRat.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>


int main()
{
    //declare string for solution
    std::string solution;
    std::string solutionToValidate;
    int max = 80;
    bool solutionIsValid = 0;

    std::cout << "Welcome to Hangrat!\nIt's just like Hangman, but the chosen word or phrase must be rodent themed\n";
    std::cout << "(I have no way to verify this)\n\n";
    std::cout << "Player1, please input your chosen word or phrase\n";
    std::cout << "Maximum " << max << " characters, only lowercase letters and spaces plz\n";
    std::getline(std::cin, solutionToValidate);

    //How do I contain validations inside a loop?
    //while solutionIsValid = 0

    while (solutionIsValid == 0) {
        //VERIFY size doesn't exceed max
        if (solutionToValidate.size() > max) {
            std::cout << "that's more than" << max << "characters, try something shorter\n";
            std::getline(std::cin, solutionToValidate);
        }
        //VERIFY valid chars
        else if (solutionToValidate.size() <= max) {
            for (int i = 0; i < solutionToValidate.size(); i++) {
                if (solutionToValidate[i] != 32 && (solutionToValidate[i] < 'a' or solutionToValidate[i] > 'z')) { //32 is space
                    std::cout << "just use lowercase letters and spaces please\n";
                    std::getline(std::cin, solutionToValidate);
                    break;
                }
                else if (i > solutionToValidate.size()) {
                    solution = solutionToValidate; //validation pass, write to solution
                    solutionIsValid = 1;

                }
            }

        }
        
        
    }

    
    
    
    


        //initialize game params outside of game loop
        int lives;
        char guess;
        std::string display = solution;
        //change all chars to underscores, leave spaces as-is
        for (int i = 0; i < display.size(); i++) {
            if (display[i] != ' ') {
                display[i] = '_';
            }
        }

        //main game loop goes here
        //what exactly is being looped? does an if condition work?
        //if (lives > 0) {
        for (lives = 6; lives > 0;) {
            bool found = 0; //CHECK loop returns to here


            std::cout << "lives remaining: " << lives << "\n";
            std::cout << display;
            std::cout << "\n";
            //TODO print prev incorrect guesses
            // would only ever need 5 or 6 prev guesses
            std::cout << "Player2 please guess a single lowercase character\n";
            std::cin >> guess;

           //TODO VERIFY guess is valid. maybe have this as its own function?
           // guess == standard alphabet character
           // guess has not been previosly guessed
           // gotta keep track of previous guesses? oh boy
           // maybe not. if it's a duplicate correct guess, game proceeds
           // if it's a duplicate incorrect guess then lives decrement, which feels bad
           // OH I need a way to print previous guesses
            //if guess is invalid, print invalid message then break/return one layer up to main game loop
            //else, proceed



            //CHECK if guess matches any of the characters in solution

            //if character matches, change display char at same index # to match, flip found to 1, and continue to next index
            //at the end, if found == 1, return back to main game loop
            //if found == 0, decrement lives and return to main game loop

            for (int i = 0; i < solution.size(); i++) {
                int j = i;
                if (guess == solution[i]) {
                    display[i] = guess; //case sensitive :(
                    found = 1;
                }
                if (i == solution.size() - 1 && found == 0) {
                    lives--;
                    break;
                }
                if (i == solution.size() - 1 && found == 1) {
                    break;
                }
            }

            
            if (display == solution) {
                std::cout << "Player2 successfully guessed the phrase: " << solution << "\n";
                std::cout << "Player2 is the cleverest rat\n";
                break;
            }


            else if (lives == 0) {
                std::cout << "Player2 ran out of lives, Player1 is the champion rat\n";
                std::cout << "if you're curious what the solution was, just look up a few lines\n";
                std::cout << "I couldn't figure out how to hide Player1's input string\n";
                break;
            }
            

          
            


        }
        




}

