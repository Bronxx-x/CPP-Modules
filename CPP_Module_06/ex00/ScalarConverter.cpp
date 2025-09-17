/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 21:15:39 by yousef            #+#    #+#             */
/*   Updated: 2025/09/13 21:47:34 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this; }

void ScalarConverter::convert(const std::string &str)
{
    if (isChar(str))
        convertFromChar(str);
    else if (isInt(str))
        convertFromInt(str);
    else if (isFloat(str))
        convertFromFloat(str);
    else if (isDouble(str))
        convertFromDouble(str);
    else if (isPseudoLiteral(str))
    {
        if (isSpecialFloat(str))
            convertFromFloat(str);
        else if (isSpecialDouble(str))
            convertFromDouble(str);
    }
    else
        std::cout << "Error: Invalid input" << std::endl;
}
bool ScalarConverter::isChar(const std::string &str)
{
    return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}
bool ScalarConverter::isInt(const std::string &str)
{
    char *endptr;
    long val = std::strtol(str.c_str(), &endptr, 10);
    return (*endptr == '\0' && val >= INT_MIN && val <= INT_MAX);
}
bool ScalarConverter::isFloat(const std::string &str)
{
    char *endptr;
    std::strtof(str.c_str(), &endptr);
    return (*endptr == 'f' && endptr != str.c_str() && *(endptr - 1) != '.');
}
bool ScalarConverter::isDouble(const std::string &str)
{
    char *endptr;
    std::strtod(str.c_str(), &endptr);
    return (*endptr == '\0' && endptr != str.c_str() && *(endptr - 1) != '.');
}
bool ScalarConverter::isSpecialFloat(const std::string &str)
{
    return (str == "nanf" || str == "+inff" || str == "-inff");
}
bool ScalarConverter::isSpecialDouble(const std::string &str)
{
    return (str == "nan" || str == "+inf" || str == "-inf");
}
bool ScalarConverter::isPseudoLiteral(const std::string &str)
{
    return isSpecialFloat(str) || isSpecialDouble(str);
}
void ScalarConverter::convertFromChar(const std::string &str)
{
    char c = str[0];
    double value = static_cast<double>(c);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
void ScalarConverter::convertFromInt(const std::string &str)
{
    int i = std::atoi(str.c_str());
    double value = static_cast<double>(i);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
void ScalarConverter::convertFromFloat(const std::string &str)
{
    float f = std::strtof(str.c_str(), NULL);
    double value = static_cast<double>(f);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
void ScalarConverter::convertFromDouble(const std::string &str)
{
    double d = std::strtod(str.c_str(), NULL);
    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}

bool ScalarConverter::isDisplayable(char c)
{
    return std::isprint(static_cast<unsigned char>(c));
}
void ScalarConverter::printChar(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!isDisplayable(static_cast<char>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}
void ScalarConverter::printInt(double value)
{
    std::cout << "int: ";
    if (std::isnan(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}
void ScalarConverter::printFloat(double value)
{
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (value == std::numeric_limits<double>::infinity())
        std::cout << "+inff" << std::endl;
    else if (value == -std::numeric_limits<double>::infinity())
        std::cout << "-inff" << std::endl;
    else
    {
        float f = static_cast<float>(value);
        std::cout << f;
        if (f - static_cast<int>(f) == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}
void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (value == std::numeric_limits<double>::infinity())
        std::cout << "+inf" << std::endl;
    else if (value == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
    else
    {
        std::cout << value;
        if (value - static_cast<int>(value) == 0)
            std::cout << ".0";
        std::cout << std::endl;
    }
}
