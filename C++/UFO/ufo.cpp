#include <iostream>
#include "ufo_functions.hpp"

int main()
{
    greet();
    std::string codeword = "codecademy";
    std::string answer = "__________";
    int misses = 0;
    std::vector<char> incorrect;
    char letter;

    bool guess = false;
    while (answer != codeword && misses < 7)
    {
        display_status(incorrect, answer);

        std::cout << "Please enter your guess: ";
        std::cin >> letter;
        for (size_t i = 0; i < codeword.length(); i++)
        {
            if (letter == codeword[i])
            {
                answer[i] = letter;
                guess = true;
            }
        }
        if (guess)
        {
            std::cout << "Correct! The aliens are stunned." << std::endl;
        }
        else
        {
            std::cout << "Incorrect! The tractor beam pulls the person in farther." << std::endl;
            incorrect.push_back(letter);
            misses++;
        }
        guess = false;
        display_misses(misses);
    }

    end_game(codeword, answer);
}
