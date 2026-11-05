#include <iostream>
#include <string>

int main() {
    std::string solution, solutionToValidate;
    int max = 50;
    bool solutionIsValid = 0;

    std::cout << "Welcome to Hangrat!\nIt's just like Hangman, but the chosen word or phrase must be rodent themed\n";
    std::cout << "(I have no way to verify this)\n\n" << "Player1, please input your chosen word or phrase\n";
    std::cout << "Maximum " << max << " characters, only lowercase letters and spaces plz\n";
    std::getline(std::cin, solutionToValidate);

    while (solutionIsValid == 0) {
        //VERIFY size doesn't exceed max
        if (solutionToValidate.size() > max) {
            std::cout << "that's more than" << max << "characters, try something shorter\n";
            std::getline(std::cin, solutionToValidate);
        }
        //VERIFY valid chars
        else if (solutionToValidate.size() <= max) {
            for (int i = 0; i <= solutionToValidate.size(); i++) {
                if (i == solutionToValidate.size()) {
                    solution = solutionToValidate; //validation pass, write to solution
                    solutionIsValid = 1;
                    break;
                }
                else if (solutionToValidate[i] != ' ' && (solutionToValidate[i] < 'a' or solutionToValidate[i] > 'z')) { //32 is space
                    std::cout << "just use lowercase letters and spaces please\n";
                    std::getline(std::cin, solutionToValidate);
                    break;
                }
            }
        }
    }
        //initialize game params outside of game loop
        int lives, maxLives = 6;
        char guess = '_'; //was getting warnings when this wasn't initialized, sus
        bool guessIsValid = 0, guessIsNew = 0;
        char incorrectGuesses[6] = {0,0,0,0,0,0};
        std::string guessToValidate, display = solution;
        //change all chars to underscores, leave spaces as-is
        for (int i = 0; i < display.size(); i++) {
            if (display[i] != ' ') {
                display[i] = '_';
            }
        }
        //move Player1's input off the standard terminal window size
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        //main game loop goes here
        for (lives = maxLives; lives > 0;) {
            bool found = 0; //CHECK loop returns to here

            std::cout << "\n" << "lives remaining: " << lives << "\n";
            //print previous incorrect guesses
            if (lives != maxLives) {
                std::cout << "previous incorrect guesses: ";
                for (int i = (maxLives - lives); i > 0; i--) {
                    std::cout << incorrectGuesses[i-1] << " ";
                }
                std::cout << "\n";
            }
            
            std::cout << display << "\n" << "Player2 please guess a single lowercase letter\n";
            std::getline(std::cin, guessToValidate);

            while (guessIsValid == 0) {
                //VERIFY single char
                if (guessToValidate.size() != 1) {
                    std::cout << "just one letter please\n";
                    std::getline(std::cin, guessToValidate);
                    break;
                }
                //VERIFY valid chars
                else {
                    //check against incorrectGuesses
                    while (guessIsNew == 0) {
                        guessIsNew = 1;
                            for (int i = 0; i < maxLives - lives; i++) {
                                if (guessToValidate[0] == incorrectGuesses[i]) {
                                    std::cout << "you've already guessed that one\n";
                                    std::getline(std::cin, guessToValidate);
                                    guessIsNew = 0;
                                }
                            }
                    }
                    
                    if (guessToValidate[0] >= 'a' && guessToValidate[0] <= 'z') {
                        guess = guessToValidate[0];
                        guessIsValid = 1; 
                        break;
                    }
                    else {
                        std::cout << "please make sure it's a lowercase letter\n";
                        std::getline(std::cin, guessToValidate);
                        break;
                    }
                }
            }
            //reset validation conditions for next time
            guessIsValid = 0;
            guessIsNew = 0;

            //CHECK if guess matches any of the characters in solution
            for (int i = 0; i < solution.size(); i++) {
                int j = i;
                if (guess == solution[i]) {
                    display[i] = guess;
                    found = 1;
                }
                if (i == solution.size() - 1 && found == 0) {
                    //incorrect guess stuff goes here
                    incorrectGuesses[maxLives - lives] = guess;
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
                std::cout << "Player2 ran out of lives, Player1 is the champion rat\n" << "if you're curious what the solution was, just look up a few lines\n";
                std::cout << "I couldn't figure out how to hide Player1's input string\n";
                break;
            }
        }
}

