#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void displayGameState(const std ::string& word, const std::string guessedLetters, int attemtsLeft){
	std::cout << "\nAttemts left: " << attemtsLeft << "\n";
    std::cout << "Word: ";
    
    for(char c : word){
    	if (guessedLetters.find(c) != std::string::npos){
    		 std::cout << c << " ";
		}else {
            std::cout << "_ ";
        }
    }

    std::cout << "\nGuessed Letters: " << guessedLetters << "\n";
}

bool isWordGuessed(const std::string& word, const std::string& guessedLetters) {
    for (char c : word) {
        if (guessedLetters.find(c) == std::string::npos) {
            return false;
        }
    }
    return true;
}

char getValidGuess(const std::string& guessedLetters) {
    char guess;
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        guess = tolower(guess);

        if (guessedLetters.find(guess) != std::string::npos) {
            std::cout << "You already guessed that letter. Try again.\n";
        } else if (!isalpha(guess)) {
            std::cout << "Invalid input. Please enter a letter.\n";
        } else {
            break;
        }
    }
    return guess;
}

int main() {
    std::vector<std::string> words = {"alpha", "hangman", "javascript", "software", "python"};
    std::srand(std::time(0));
    std::string word = words[std::rand() % words.size()];

    std::string guessedLetters = "";
    int attemptsLeft = 6;
    bool gameWon = false;

    while (attemptsLeft > 0 && !gameWon) {
        displayGameState(word, guessedLetters, attemptsLeft);
        char guess = getValidGuess(guessedLetters);
        guessedLetters += guess;

        if (word.find(guess) == std::string::npos) {
            attemptsLeft--;
        }

        if (isWordGuessed(word, guessedLetters)) {
            gameWon = true;
        }
    }

    if (gameWon) {
        std::cout << "Congratulations! You guessed the word: " << word << "\n";
    } else {
        std::cout << "You lost! The correct word was: " << word << "\n";
    }

    return 0;
	}
