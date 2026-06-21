/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telcash <telcash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:33:13 by telcash           #+#    #+#             */
/*   Updated: 2026/06/20 21:39:40 by telcash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): _exchangeRates() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _exchangeRates(other._exchangeRates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readDatabase(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open database file: " + std::string(filename));
    }
    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
    {
        throw std::runtime_error("Invalid database format: missing header");
    }
    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
        {
            throw std::runtime_error("Invalid database format: missing comma");
        }
        std::string date = line.substr(0, commaPos);
        double rate = std::atof(line.substr(commaPos + 1).c_str());
        _exchangeRates[date] = rate;
    }
    file.close();
}
bool BitcoinExchange::_isValidDate(const std::string& date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
    {
        return false;
    }
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
        {
            continue;
        }
        if (!std::isdigit(date[i]))
        {
            return false;
        }
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    {
        return false;
    }
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
    {
        return false;
    }
    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeapYear && day > 29) || (!isLeapYear && day > 28))
        {
            return false;
        }
    }
    return true;
}

double BitcoinExchange::_getRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);
    if (it != _exchangeRates.end())
    {
        return it->second;
    }
    else 
    {
        std::map<std::string, double>::const_iterator lower = _exchangeRates.lower_bound(date);
        if (lower == _exchangeRates.begin())
        {
            return lower->second;
        }
        --lower;
        return lower->second;
    }
}

void BitcoinExchange::processData(const char* filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open data file: " + std::string(filename));
    }
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }
        if (line == "date | value")
        {
            continue;
        }
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pipePos - 1);
        if (!_isValidDate(date))
        {
            std::cerr << "Error: invalid date => " << date << std::endl;
            continue;
        }
        double value = std::atof(line.substr(pipePos + 2).c_str());
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        double rate = _getRate(date);
        std::cout << date << " => " << value << " = " << rate * value << std::endl;
    }
    file.close();
}
