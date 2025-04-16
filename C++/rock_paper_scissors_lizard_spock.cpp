#include <iostream>
#include <stdlib.h>

/*
Game:
Rock, Paper, Scissors, Lizard, Spock

Rules:
Scissors cuts Paper.
Paper covers Rock.
Rock crushes Lizard.
Lizard poisons Spock.
Spock smashes Scissors.
Scissors decapitate Lizard.
Lizard eats Paper.
Paper disproves Spock.
Spock vaporizes Rock.
(and as it always has) Rock crushes Scissors.
*/

int main()
{
    // Live long and prosper
    srand(time(NULL));
    int computer = rand() % 5 + 1;
    int user = 0;

    std::cout << "====================" << std::endl;
    std::cout << "rock paper scissors!" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "1) ✊" << std::endl;
    std::cout << "2) ✋" << std::endl;
    std::cout << "3) ✌️" << std::endl;
    std::cout << "4) lizard" << std::endl;
    std::cout << "5) spock" << std::endl;
    std::cout << "shoot! " << std::endl
              << std::endl;

    std::cin >> user;

    std::cout << "CPU chose ";
    if (user == 1) // rock
    {
        if (computer == 1)
        {
            std::cout << "rock, tie! " << std::endl;
        }
        else if (computer == 2)
        {
            std::cout << "paper, you lose! " << std::endl;
        }
        else if (computer == 3)
        {
            std::cout << "scissors, you win! " << std::endl;
        }
        else if (computer == 4)
        {
            std::cout << "lizard, you win! " << std::endl;
        }
        else if (computer == 5)
        {
            std::cout << "spock, you lose! " << std::endl;
        }
    }
    else if (user == 2) // paper
    {
        if (computer == 1)
        {
            std::cout << "rock, you win! " << std::endl;
        }
        else if (computer == 2)
        {
            std::cout << "paper, tie! " << std::endl;
        }
        else if (computer == 3)
        {
            std::cout << "scissors, you lose! " << std::endl;
        }
        else if (computer == 4)
        {
            std::cout << "lizard, you lose! " << std::endl;
        }
        else if (computer == 5)
        {
            std::cout << "spock, you win! " << std::endl;
        }
    }
    else if (user == 3) // scissors
    {
        if (computer == 1)
        {
            std::cout << "rock, you lose! " << std::endl;
        }
        else if (computer == 2)
        {
            std::cout << "paper, you win! " << std::endl;
        }
        else if (computer == 3)
        {
            std::cout << "scissors, tie! " << std::endl;
        }
        else if (computer == 4)
        {
            std::cout << "lizard, you win! " << std::endl;
        }
        else if (computer == 5)
        {
            std::cout << "spock, you lose! " << std::endl;
        }
    }
    else if (user == 4) // lizard
    {
        if (computer == 1)
        {
            std::cout << "rock, you lose! " << std::endl;
        }
        else if (computer == 2)
        {
            std::cout << "paper, you win! " << std::endl;
        }
        else if (computer == 3)
        {
            std::cout << "scissors, you lose! " << std::endl;
        }
        else if (computer == 4)
        {
            std::cout << "lizard, tie! " << std::endl;
        }
        else if (computer == 5)
        {
            std::cout << "spock, you win! " << std::endl;
        }
    }
    else if (user == 5) // spock
    {
        if (computer == 1)
        {
            std::cout << "rock, you win! " << std::endl;
        }
        else if (computer == 2)
        {
            std::cout << "paper, you lose! " << std::endl;
        }
        else if (computer == 3)
        {
            std::cout << "scissors, you win! " << std::endl;
        }
        else if (computer == 4)
        {
            std::cout << "lizard, lose! " << std::endl;
        }
        else if (computer == 5)
        {
            std::cout << "spock, tie! " << std::endl;
        }
    }
}
