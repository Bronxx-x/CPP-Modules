/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-03 11:13:01 by yhamdan           #+#    #+#             */
/*   Updated: 2025-10-03 11:13:01 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 #include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) { (void)other; return *this; }


int BitcoinExchange::dateCheck(const std::string& date) const{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return -1;

    int year, month, day;
    try {
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
    } catch (...) {
        return -1;
    }

    if (month < 1 || month > 12 || day < 1)
        return -1;

    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return -1;

    return 0;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
 {
    if (dateCheck(date) == -1) {
        return -1;
    }
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
    if (it != exchangeRates.end() && it->first == date) {
        return it->second;
    }
    if (it == exchangeRates.begin()) {
        throw std::runtime_error("No exchange rate available for the given date or earlier");
    }
    --it;
    return it->second;
}

std::string BitcoinExchange::skipSpaces(const std::string& str) const{
    size_t start = 0, end = str.length();
    while (start < end && (str[start] == ' ' || str[start] == '\t')) start++;
    while (end > start && (str[end-1] == ' ' || str[end-1] == '\t')) end--;
    return str.substr(start, end - start);
}

int BitcoinExchange::processFile(const std::string& inputFile, char delimiter)
{
    std::ifstream input(inputFile.c_str());
    if (!input.is_open())
        throw std::runtime_error("Could not open file: " + inputFile);

    std::string line;
    std::getline(input, line);
    if ((line != "date,exchange_rate" && delimiter == ',') ||
        (line != "date | value" && delimiter == '|'))
        throw std::runtime_error("Invalid header in file: " + inputFile);
    while (std::getline(input, line))
    {
        std::istringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, delimiter) || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string cleanDate = skipSpaces(date);
        std::string cleanValueStr = skipSpaces(valueStr);

        std::stringstream valStream(cleanValueStr);
        float value;
        if (!(valStream >> value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (delimiter == ',')
        {
            if (dateCheck(cleanDate) == -1) {
                std::cerr << "Error: Invalid date format => " << cleanDate << std::endl;
                continue;
            }
            else
                exchangeRates[cleanDate] = value;
        }
        else
        {
            std::string valueString = cleanValueStr;
            long long valueNum = 0;
            std::istringstream iss(valueString);
            iss >> valueNum;

            if (!iss || valueNum < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (valueNum > 2147483647LL) {
                std::cerr << "Error: number exceeds int max." << std::endl;
                continue;
            }
            try
            {
                if (dateCheck(cleanDate) == -1)
                    std::cerr << "Error: Invalid date format => " << cleanDate << std::endl;
                else
                {
                    float rate = getExchangeRate(cleanDate);
                    std::cout << cleanDate << " => " << value << " = " << value * rate << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    input.close();
    return 0;
}

