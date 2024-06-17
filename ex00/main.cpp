/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:56:06 by facarval          #+#    #+#             */
/*   Updated: 2024/06/03 18:27:18 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{

    if (argc != 2)
    {
        std::cerr << red << "The program needs 1 argument" << reset << std::endl;
        return 1;
    }
    std::string str = argv[1];
    ScalarConverter::convert(str);

    return 0;
}