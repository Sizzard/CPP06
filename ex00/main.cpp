/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:56:06 by facarval          #+#    #+#             */
/*   Updated: 2024/05/17 15:59:20 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{

    std::string str;

    std::cout << "Input : ";
    std::cin >> str;

    ScalarConverter::convert(str);

    return 0;
}