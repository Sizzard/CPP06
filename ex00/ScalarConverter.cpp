/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:58:46 by facarval          #+#    #+#             */
/*   Updated: 2024/05/21 10:11:02 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdio.h>

ScalarConverter::ScalarConverter()
{
    return;
}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
    *this = cpy;
    return;
}

ScalarConverter::~ScalarConverter()
{
    return;
}

void from_char(long long res)
{
    if (res > 255 || res < 0)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(res) == 0)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(res) << std::endl;
    if (res > 2147483647 || res < -2147483648)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(res) << std::endl;
    std::cout << "float: " << static_cast<float>(res) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(res) << ".0" << std::endl;

    return;
}

void from_int(long long integer)
{
    if (integer > 255 || integer < 0)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(integer) == 0)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(integer) << std::endl;
    if (integer > 2147483647 || integer < -2147483648)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(integer) << std::endl;
    std::cout << "float: " << static_cast<float>(integer) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(integer) << ".0" << std::endl;
}

void from_float(std::string const &str, float floating)
{
    if (floating > 255 || floating < 0)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(floating) == 0)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(floating) << std::endl;
    if (floating > 2147483647.0 || floating < -2147483648)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(floating) << std::endl;
    if (floating > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else if (strcmp(&str[str.length() - 2], ".0") == 0 || strcmp(&str[str.length() - 3], ".0f") == 0)
        std::cout << "float: " << static_cast<float>(floating) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(floating) << "f" << std::endl;
    if (strcmp(&str[str.length() - 2], ".0") == 0 || strcmp(&str[str.length() - 3], ".0f") == 0)
        std::cout << "double: " << static_cast<double>(floating) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(floating) << std::endl;

    return;
}

void from_double(std::string const &str, double doubl)
{
    if (doubl > 255 || doubl < 0)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(doubl) == 0)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(doubl) << std::endl;
    if (doubl > 2147483647 || doubl < -2147483648)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(doubl) << std::endl;
    if (strcmp(&str[str.length() - 2], ".0") == 0 || strcmp(&str[str.length() - 3], ".0f") == 0)
        std::cout << "float: " << static_cast<float>(doubl) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(doubl) << "f" << std::endl;
    if (strcmp(&str[str.length() - 2], ".0") == 0 || strcmp(&str[str.length() - 3], ".0f") == 0)
        std::cout << "double: " << static_cast<double>(doubl) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(doubl) << std::endl;

    return;
}

int detect_type(std::string const &str)
{
    unsigned long i = 0;
    int counter = 0;

    if (str[str.length() - 1] == '.')
        return -1;
    while (i < str.length())
    {
        if (str[i] == '.')
            counter++;
        i++;
    }
    if (counter > 1)
        return -1;
    if (str.length() == 1 && isprint(str[0]) != 0)
    {
        if (isdigit(str[0]))
            return INT;
        return CHAR;
    }
    i = 0;
    if (str[i] == '-')
        i++;
    while (i < str.length() && isdigit(str[i]))
    {
        i++;
    }
    if (str[i] != '.')
    {
        if (str[i] && isdigit(str[i + 1]) == 0)
        {
            return -1;
        }
        return INT;
    }
    i++;
    while (i < str.length() && isdigit(str[i]))
    {
        i++;
    }
    if (str[i] == 'f')
    {
        if (isdigit(str[i - 1]))
            return FLOAT;
        return -1;
    }
    return DOUBLE;
}

bool special_case(std::string const &str)
{
    double nb = std::strtod(str.c_str(), NULL);
    
    if (errno != 0)
    {
        std::cout << "Char: impossible\nInt: impossible\nFloat: impossible" << std::endl
                  << "Double: impossible" << std::endl;
    }
    else if (strcmp(str.c_str(), "inf") == 0 || strcmp(str.c_str(), "+inf") == 0 || strcmp(str.c_str(), "inff") == 0 || strcmp(str.c_str(), "+inff") == 0)
    {

        std::cout << "Char: impossible\nInt: impossible\nFloat: " << static_cast<float>(nb) << "f" << std::endl
                  << "Double: " << static_cast<double>(nb) << std::endl;
    }
    else if (strcmp(str.c_str(), "-inf") == 0 || strcmp(str.c_str(), "-inff") == 0)
    {

        std::cout << "Char: impossible\nInt: impossible\nFloat: " << static_cast<float>(nb) << "f" << std::endl
                  << "Double: " << static_cast<double>(nb) << std::endl;
    }
    else if (strcmp(str.c_str(), "nan") == 0)
    {

        std::cout << "Char: impossible\nInt: impossible\nFloat: " << static_cast<float>(nb) << "f" << std::endl
                  << "Double: " << static_cast<double>(nb) << std::endl;
    }
    else
        return false;
    return true;
}

void ScalarConverter::convert(std::string str)
{

    int type = detect_type(str);
    std::stringstream ss;

    if (strncmp(str.c_str(), ".", 1) == 0)
    {
        std::cout << "INVALID ARGUMENT : " << str << std::endl;
        return;
    }

    if (special_case(str) == true)
    {
        return;
    }

    switch (type)
    {
    case INT:
    {

        long long res;
        ss << str;
        ss >> res;
        from_int(res);
    }
    break;
    case CHAR:
    {

        unsigned char res;
        ss << str;
        ss >> res;
        from_char(res);
    }
    break;
    case FLOAT:
    {
        errno = 0;

        float res = std::strtof(str.c_str(), NULL);
        if (special_case(str) == true)
            return;
        from_float(str, res);
    }
    break;
    case DOUBLE:
    {
        errno = 0;

        double res = std::strtod(str.c_str(), NULL);
        if (special_case(str) == true)
            return;
        from_double(str, res);
    }
    break;
    default:
        std::cout << "INVALID ARGUMENT : " << str << std::endl;
        break;
    }
    return;
}