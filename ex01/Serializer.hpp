/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:16:05 by facarval          #+#    #+#             */
/*   Updated: 2024/05/21 10:47:30 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string blue("\033[1;34m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

class Serializer
{

public:
    Serializer();
    Serializer(Serializer const &to_cpy);
    virtual Serializer &operator=(Serializer const &cpy) = 0;
    virtual ~Serializer();

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};