/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:58:38 by facarval          #+#    #+#             */
/*   Updated: 2024/06/03 18:20:58 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
#include <limits>
#include <iomanip>
#include <stdlib.h>
#include <cerrno>
#include <cmath>
#include <ios>

const std::string red("\033[1;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string blue("\033[1;34m");
const std::string cyan("\033[1;36m");
const std::string magenta("\033[1;35m");
const std::string reset("\033[0m");

enum
{
    CHAR = 0,
    INT = 1,
    FLOAT = 2,
    DOUBLE = 3
};

class ScalarConverter
{

public:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &to_cpy);
    virtual ScalarConverter &operator=(ScalarConverter const &cpy) = 0;
    virtual ~ScalarConverter();

    static void convert(std::string str);
};