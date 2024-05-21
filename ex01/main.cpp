/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facarval <facarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:15:49 by facarval          #+#    #+#             */
/*   Updated: 2024/05/21 11:21:12 by facarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data input;
    input.name = "Facarval";
    input.age = 18;

    std::cout << "Non serialized name : " << input.name << std::endl;
    std::cout << "Non serialized age : " << input.age << std::endl;

    uintptr_t output_ptr = Serializer::serialize(&input);

    std::cout << "\nSerialized\n" << std::endl;

    Data *output = Serializer::deserialize(output_ptr);

    std::cout << "Deserialized name : " << output->name << std::endl;
    std::cout << "Deserialized age : " << output->age << std::endl;
    return 0;
}