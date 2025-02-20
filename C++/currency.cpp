#include <iostream>
#include <string>

int main()
{
    double pesos, reais, soles;
    double dollars;

    std::cout << "Enter number of Colombian Pesos:" << std::endl;
    std::cin >> pesos;
    std::cout << "Enter number of Brazilian Reais:" << std::endl;
    std::cin >> reais;
    std::cout << "Enter number of Peruvian Soles:" << std::endl;
    std::cin >> soles;

    dollars = 0.00032 * pesos + 0.27 * reais + 0.3 * soles;
    std::cout << "US Dollars = $" << dollars << std::endl;
    return 0;
};