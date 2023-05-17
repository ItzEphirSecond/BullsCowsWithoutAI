#include "Game.h"

bool checkTweaks(std::string num)
{
    for (int i = 0; i < num.length() - 1; i++)
        for (int j = 0; j < num.length(); j++)
            if (num[i] == num[j] && i != j)
                return false;
    return true;
}

void Game::start()
{
    bool youDied = true;
    // std::cout << randomNumber() << std::endl;
    int numberToSuggest = randomNumber();
    for (int i = 0; i < 10; i++)
    {
        std::string enteredNumber;
        std::cout << i + 1 << " ";
        std::cin >> enteredNumber;
        std::string result = allegedNumber(enteredNumber);
        if (result != "xxxx")
        {
            if (result != "")
                std::cout << result << std::endl;
            else
                std::cout << "...nothing..." << std::endl;
        }
        else
        {
            std::cout << "win" << std::endl;
            youDied = false;
            break;
        }
    }

    if (youDied)
    {
        std::cout << "YOU DIED (yes, it`s Dark Souls reference)" << std::endl;
        std::cout << "The number was: " << numberToSuggest;
    }
}

int Game::randomNumber()
{
    std::srand(std::time(0));

    int num;
    bool isDouble = false;

    do
    {
        num = std::rand() % 9000 + 1000;
        isDouble = checkTweaks(std::to_string(num));
    } while (!isDouble);

    number = std::to_string(num);

    return num;
}

std::string Game::allegedNumber(std::string entered)
{
    std::string result = "";

    for (int i = 0; i < entered.length(); i++)
        for (int j = 0; j < number.length(); j++)
            if (entered[i] == number[j])
                result += (i == j) ? "x" : "o";

    return result;
}
