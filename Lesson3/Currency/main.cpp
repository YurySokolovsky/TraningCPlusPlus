#include <iostream>
#include <map>
#include <iomanip>
#include "Currency.h"

//Creation of money rates map
void createMoneyExchangeMap(std::map<Currency<std::string, std::string>, long long>& exchangeRates)
{
    std::string moneyCode = "BYN";
    std::string moneyName = "Belarusian ruble";
    Currency<std::string, std::string> byn(moneyCode, moneyName);
    exchangeRates.insert(std::make_pair(byn, 10000));

    moneyCode = "RUR";
    moneyName = "Ruble";
    Currency<std::string, std::string> rur(moneyCode, moneyName);
    exchangeRates.insert(std::make_pair(rur, 34155));

    moneyCode = "USD";
    moneyName = "Dollar";
    Currency<std::string, std::string> usd(moneyCode, moneyName);
    exchangeRates.insert(std::make_pair(usd, 25712));

    moneyCode = "EUR";
    moneyName = "Euro";
    Currency<std::string, std::string> eur(moneyCode, moneyName);
    exchangeRates.insert(std::make_pair(eur, 29314));
}

//Function for money count
double countMoney(std::map<Currency<std::string, std::string>, long long>& exchangeRates, std::string& moneyType, double& moneyCount)
{
    for (auto n : exchangeRates)
    {
       auto currency = n.first;
       if (currency.getCode() == moneyType)
       {
          auto currencyRate = n.second;
          return currencyRate * moneyCount / 10000;
       }
    }
    return 0;
}

//Function to insert the amount of money for a particular type of currency 
double insertMoneyCount(std::map<Currency<std::string, std::string>, long long>& exchangeRates, std::string& moneyType)
{
    double moneyCount;
    bool isCorrectValue = false;

    while (!isCorrectValue)
    {

        std::cout << "Input money count :";
        std::cin >> moneyCount;

        if (std::cin.fail() || moneyCount < 0)  //Check moneyCount value
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            
            char c;
            std::cout << "Incorrect count of money value! If you want repeat press 'Y' :";
            std::cin >> c;

            if (toupper(c) != 'Y')
            {
                isCorrectValue = true;
            }
        }
        else
        {
            isCorrectValue = true;
            return countMoney(exchangeRates, moneyType, moneyCount);
        }
    }

    return 0;
}

//Function for choose money type
double insertMoneyType(std::map<Currency<std::string, std::string>, long long>& exchangeRates)
{
    //Displaying a list of available currencies
    std::cout << "Avaliable money ";
    
    for (auto n : exchangeRates)
    {
        auto currency = n.first;
        std::cout << currency.getCode() << " | ";
    }
    std::cout << std::endl;

    //Check currency type
    bool isCorrectType = false;
    std::string moneyType;
    
    while (!isCorrectType)
    {
        std::cout << "Input money type : ";
        std::cin >> moneyType;

        for (auto n : exchangeRates)
        {
            auto currency = n.first;
            if (currency.getCode() == moneyType)
            {
                isCorrectType = true;
                return insertMoneyCount(exchangeRates, moneyType);
            }
        }

        //Incorrect money type message
        if (!isCorrectType)
        {
            char c;
            std::cout << "Incorrect money type! If you want repeat press 'Y' : ";
            std::cin >> c;
            if (toupper(c) != 'Y')
            {
                isCorrectType = true;
            }
        }
    }

    return 0;
}

//Function for total money count
void moneyInPoketCount(std::map<Currency<std::string, std::string>, long long>& exchangeRates)
{
    bool isRepeatInsert = false;
    double moneyCount = 0;

    while (!isRepeatInsert)
    {
        moneyCount += insertMoneyType(exchangeRates);
        char c;

        std::cout << "If you want insert new Currency press 'Y' : ";
        std::cin >> c;
        std::cout << "=====================================================" << std::endl;
        if (toupper(c) != 'Y')
        {
            isRepeatInsert = true;
        }
    }
    std::cout << "The current amount of money Belarusian rubles is equal to : " << std::fixed << std::setprecision(2) << moneyCount << std::endl;
}

int main()
{
    std::map<Currency<std::string, std::string>, long long> exchangeRates;
    createMoneyExchangeMap(exchangeRates);
    moneyInPoketCount(exchangeRates);
}