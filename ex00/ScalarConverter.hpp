/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:58:38 by facarval          #+#    #+#             */
/*   Updated: 2024/05/21 10:11:22 by facarval         ###   ########.fr       */
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